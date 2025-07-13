PORTNAME=		sogo
PORTVERSION=		5.12.3
CATEGORIES=		www gnustep
MASTER_SITES=		https://packages.sogo.nu/sources/
PKGNAMESUFFIX=		-${FLAVOR}
DISTNAME=		SOGo-${PORTVERSION}

MAINTAINER=		acm@FreeBSD.org
COMMENT=		Groupware server with a focus on scalability and open standards
WWW=			https://sogo.nu/

LICENSE=		GPLv2

FLAVORS=		mysql mysqlactivesync pgsql pgsqlactivesync
FLAVOR?=		${FLAVORS:[1]}

LIB_DEPENDS=		libmemcached.so:databases/libmemcached \
			libcurl.so:ftp/curl \
			libsodium.so:security/libsodium \
			libzip.so:archivers/libzip \
			libytnef.so:converters/ytnef

RUN_DEPENDS=		zip:archivers/zip

USES=			cpe gettext-runtime gnustep objc pkgconfig shebangfix ssl
CPE_VENDOR=		inverse
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}/sogo
USE_RC_SUBR=		sogod

SHEBANG_LANG=		python
SHEBANG_FILES=		${WRKSRC}/SoObjects/SOGo/gen-saml2-exceptions.py

CONFIGURE_ARGS+=	--disable-debug --disable-strip

mysql_CONFLICTS_INSTALL=        sogo2 ${PORTNAME}-pgsql ${PORTNAME}-pgsqlactivesync ${PORTNAME}-mysqlactivesync
pgsql_CONFLICTS_INSTALL=        sogo2 ${PORTNAME}-mysql ${PORTNAME}-mysqlactivesync ${PORTNAME}-pgsqlactivesync
mysqlactivesync_CONFLICTS_INSTALL=sogo2 ${PORTNAME}-mysql ${PORTNAME}-pgsql ${PORTNAME}-pgsqlactivesync
pgsqlactivesync_CONFLICTS_INSTALL=sogo2 ${PORTNAME}-mysql ${PORTNAME}-pgsql ${PORTNAME}-mysqlactivesync

OPTIONS_DEFAULT=	MEMCACHED MFA SAML2
OPTIONS_DEFINE=		ACTIVESYNC MEMCACHED MFA SAML2
OPTIONS_SUB=		yes
OPTIONS_SINGLE_DATABASE=MYSQL PGSQL
OPTIONS_SINGLE=         DATABASE
DATABASE_DESC=          Database support

ACTIVESYNC_DESC=	Enable support for ActiveSync protocol
MEMCACHED_DESC=		Install memcached
MFA_DESC=		Enable support for multi-factor authentication
SAML2_DESC=		Enable support for SAML2 authentication

ACTIVESYNC_LIB_DEPENDS=	libwbxml2.so:textproc/libwbxml

MEMCACHED_RUN_DEPENDS=	${LOCALBASE}/bin/memcached:databases/memcached

MFA_LIB_DEPENDS=	liboath.so:security/oath-toolkit
MFA_CONFIGURE_ON=	--enable-mfa

SAML2_LIB_DEPENDS=	liblasso.so:security/lasso
SAML2_USES=		python:build gnome
SAML2_USE=		gnome=glib20
SAML2_CONFIGURE_ON=	--enable-saml2

PGSQL_BUILD_DEPENDS=	${LOCALBASE}/GNUstep/Local/Library/GDLAdaptors-4.9/PostgreSQL.gdladaptor/PostgreSQL:devel/sope@pgsql
PGSQL_RUN_DEPENDS=	${LOCALBASE}/GNUstep/Local/Library/GDLAdaptors-4.9/PostgreSQL.gdladaptor/PostgreSQL:devel/sope@pgsql
MYSQL_BUILD_DEPENDS=	${LOCALBASE}/GNUstep/Local/Library/GDLAdaptors-4.9/MySQL.gdladaptor/MySQL:devel/sope@mysql
MYSQL_RUN_DEPENDS=	${LOCALBASE}/GNUstep/Local/Library/GDLAdaptors-4.9/MySQL.gdladaptor/MySQL:devel/sope@mysql

USERS=			sogod
GROUPS=			sogod

SUB_FILES+=		pkg-message
SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}

.if ${FLAVOR:U} == pgsql
OPTIONS_DEFAULT+=	PGSQL
.endif

.if ${FLAVOR:U} == mysql
OPTIONS_DEFAULT+=	MYSQL
.endif

.if ${FLAVOR:U} == mysqlactivesync
OPTIONS_DEFAULT+=	ACTIVESYNC MYSQL
.endif

.if ${FLAVOR:U} == pgsqlactivesync
OPTIONS_DEFAULT+=	ACTIVESYNC PGSQL
.endif

.include <bsd.port.pre.mk>

.if ${OPSYS} == FreeBSD
CPPFLAGS+=	-Wno-error=int-conversion -Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${GREP} -rlF '/etc/sogo' ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} 's#/etc/sogo#${PREFIX}/etc/sogo#g'
	@${REINPLACE_CMD} -e 's|/usr/lib/GNUstep/|${LOCALBASE}/GNUstep/Local/Library|g' ${WRKSRC}/Apache/SOGo.conf
	@${REINPLACE_CMD} -e 's|srcBuffer\[stringLength\]|srcBuffer\[stringLength+1\]|g' \
		${WRKSRC}/SoObjects/SOGo/NSData+Crypto.m
	@${RM} ${WRKSRC}/Scripts/*.bak

post-patch-ACTIVESYNC-on:
	@${REINPLACE_CMD} -e 's/Tools/Tools ActiveSync/' ${WRKSRC}/GNUmakefile

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

post-install:
	${MKDIR} ${STAGEDIR}/var/spool/sogo
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/sogo.conf ${STAGEDIR}${ETCDIR}/sogo.conf.sample
	${INSTALL_DATA} ${WRKSRC}/Apache/SOGo.conf ${STAGEDIR}${ETCDIR}/SOGo-Apache.conf.sample
	${INSTALL_DATA} ${WRKSRC}/Apache/SOGo-apple-ab.conf ${STAGEDIR}${ETCDIR}/SOGo-apple-ab.Apache.conf.sample
	${INSTALL_DATA} ${FILESDIR}/expire-autoreply.creds.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${FILESDIR}/ealarms-notify.creds.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${FILESDIR}/cron-ealarms-notify.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/
	${INSTALL_DATA} ${FILESDIR}/cron-expire-autoreply.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/
	cd ${WRKSRC}/Scripts && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}

.include <bsd.port.post.mk>
