PORTNAME=		sogo
PORTVERSION=		5.1.1
CATEGORIES=		www gnustep
MASTER_SITES=		http://www.sogo.nu/files/downloads/SOGo/Sources/
DISTNAME=		SOGo-${PORTVERSION}

MAINTAINER=		acm@FreeBSD.org
COMMENT=		Groupware server with a focus on scalability and open standards

LICENSE=		GPLv2

LIB_DEPENDS=		libmemcached.so:databases/libmemcached \
			libcurl.so:ftp/curl \
			libsodium.so:security/libsodium \
			libzip.so:archivers/libzip \
			libDOM.so:devel/sope
RUN_DEPENDS=		zip:archivers/zip

OPTIONS_DEFAULT=	MFA
OPTIONS_DEFINE=		ACTIVESYNC MFA SAML2
OPTIONS_SUB=		yes

ACTIVESYNC_DESC=	Enable support for ActiveSync protocol
MFA_DESC=		Enable support for multi-factor authentication
SAML2_DESC=		Enable support for SAML2 authentication

SAML2_USES=		python:build gnome
SAML2_USE=		gnome=glib20

ACTIVESYNC_LIB_DEPENDS=	libwbxml2.so:textproc/wbxml2
MFA_LIB_DEPENDS=	liboath.so:security/oath-toolkit
SAML2_LIB_DEPENDS=	liblasso.so:security/lasso

MFA_CONFIGURE_ON=	--enable-mfa
MFA_CONFIGURE_OFF=	--disable-mfa
SAML2_CONFIGURE_ON=	--enable-saml2

USERS=			sogod
GROUPS=			sogod
USES=			gettext-runtime gnustep objc pkgconfig shebangfix ssl
USE_GNUSTEP=		base build
USE_LDCONFIG=		${GNUSTEP_LOCAL_LIBRARIES}/sogo

SHEBANG_LANG=		python
SHEBANG_FILES=		${WRKSRC}/SoObjects/SOGo/gen-saml2-exceptions.py

CONFLICTS?=		sogo[2-4]-activesync-[0-9]* sogo[2-4]-[0-9]*

USE_RC_SUBR=		sogod

SUB_FILES+=		pkg-message
SUB_LIST+=		GNUSTEP_LOCAL_TOOLS=${GNUSTEP_LOCAL_TOOLS} \
			GNUSTEP_MAKEFILES=${GNUSTEP_MAKEFILES}
CONFIGURE_ARGS+=		--disable-debug --enable-strip

post-patch:
	@${GREP} -rlF '/etc/sogo' ${WRKSRC} \
		| ${XARGS} ${REINPLACE_CMD} 's#/etc/sogo#${PREFIX}/etc/sogo#g'
	@${REINPLACE_CMD} -e 's|/usr/lib/GNUstep/|${LOCALBASE}/GNUstep/Local/Library|g' ${WRKSRC}/Apache/SOGo.conf

post-patch-ACTIVESYNC-on:
	@${REINPLACE_CMD} -e 's/Tools/Tools ActiveSync/' ${WRKSRC}/GNUmakefile

do-configure:
	cd ${WRKSRC} ; . ${GNUSTEP_MAKEFILES}/GNUstep.sh ; ./configure ${CONFIGURE_ARGS}

post-install:
	${MKDIR} ${STAGEDIR}/var/spool/sogo
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKSRC}/Scripts/sogo.conf ${STAGEDIR}${ETCDIR}/sogo.conf.sample
	${INSTALL_DATA} ${WRKSRC}/Apache/SOGo.conf ${STAGEDIR}${ETCDIR}/SOGo-Apache.conf.sample
	${INSTALL_DATA} ${WRKSRC}/Apache/SOGo-apple-ab.conf ${STAGEDIR}${ETCDIR}/SOGo-apple-ab.Apache.conf.sample
	${INSTALL_DATA} ${FILESDIR}/expire-autoreply.creds.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${FILESDIR}/ealarms-notify.creds.sample ${STAGEDIR}${ETCDIR}/
	${INSTALL_DATA} ${FILESDIR}/cron-ealarms-notify.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/
	${INSTALL_DATA} ${FILESDIR}/cron-expire-autoreply.sample ${STAGEDIR}${PREFIX}/GNUstep/Local/Tools/Admin/

.include <bsd.port.mk>
