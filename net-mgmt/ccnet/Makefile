# $FreeBSD$

PORTNAME=	ccnet
PORTVERSION=	5.1.3
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-server
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENCE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libglib-2.0.so:devel/glib20 \
		libsqlite3.so:databases/sqlite3 \
		libzdb.so:databases/libzdb \
		libuuid.so:misc/e2fsprogs-libuuid \
		libevent.so:devel/libevent2 \
		libjansson.so:devel/jansson \
		libldap.so:net/openldap24-client

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		autoreconf gettext libtool localbase pathfix pkgconfig \
		python:-2.7 shebangfix
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
SHEBANG_FILES=	tools/*.py
PATHFIX_MAKEFILEIN=	Makefile.am

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-server --enable-ldap
INSTALL_TARGET=	install-strip

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEABIN=		${SEAFILE_SERVER}/seafile/bin
SEALIB=		${SEAFILE_SERVER}/seafile/lib

USERS=		seafile
GROUPS=		${USERS}

PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR}

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEABIN} ${STAGEDIR}${PREFIX}/${SEALIB}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-init ${STAGEDIR}${PREFIX}/${SEABIN}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-server ${STAGEDIR}${PREFIX}/${SEABIN}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-servtool ${STAGEDIR}${PREFIX}/${SEABIN}
	${RM} ${STAGEDIR}${PREFIX}/bin/ccnet-init \
		${STAGEDIR}${PREFIX}/bin/ccnet-server \
		${STAGEDIR}${PREFIX}/bin/ccnet-servtool
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}
	${LN} -s ${PREFIX}/${SEABIN}/ccnet-server ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
