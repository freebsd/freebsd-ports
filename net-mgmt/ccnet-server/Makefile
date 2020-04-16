# $FreeBSD$

PORTNAME=	ccnet-server
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAFILE_VER}
DISTVERSIONSUFFIX=	-server
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Internal communication framework for Seafile server

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libsqlite3.so:databases/sqlite3 \
		libzdb.so:databases/libzdb \
		libuuid.so:misc/e2fsprogs-libuuid \
		libevent.so:devel/libevent \
		libjansson.so:devel/jansson

USES=		autoreconf compiler:c11 gnome libtool localbase mysql:client \
		pathfix pgsql pkgconfig python:3.6+ shebangfix ssl
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

CONFLICTS=	ccnet-[0-9]*

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl \
		-lcrypto" PKG_CONFIG_PATH="${WRKDIR}/pkgconfig"

GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ldap
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

.include <bsd.port.pre.mk>

_PKGCONFIGDIR=	${WRKDIR}/pkgconfig

post-patch:
	@${MKDIR} ${_PKGCONFIGDIR}
.if ${MYSQL_FLAVOUR} == mariadb
# If mariadb is the selected flavor, link the pc file as
# mysqlclient so PKG_CHECK_MODULES can find it. Mariadb
# doesn't supply this file in the same way other flavours do.
	@${LN} -sf ${LOCALBASE}/libdata/pkgconfig/libmariadb.pc \
		${_PKGCONFIGDIR}/mysqlclient.pc
.elif ${SSL_DEFAULT} == base
# Add bogus pc file to satisfy mysqlclient depend for ssl=base
	@${PRINTF} 'Name:\nDescription:\nVersion:' \
		>${_PKGCONFIGDIR}/openssl.pc
.endif

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEABIN} ${STAGEDIR}${PREFIX}/${SEALIB}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-init ${STAGEDIR}${PREFIX}/${SEABIN}
	${INSTALL_PROGRAM} ${STAGEDIR}${PREFIX}/bin/ccnet-server ${STAGEDIR}${PREFIX}/${SEABIN}
	${RM} ${STAGEDIR}${PREFIX}/bin/ccnet-init \
		${STAGEDIR}${PREFIX}/bin/ccnet-server
	(cd ${STAGEDIR}${PREFIX}/lib && \
		${COPYTREE_SHARE} ${PYTHON_VERSION} ${STAGEDIR}${PREFIX}/${SEALIB})
	@${RM} -rf ${STAGEDIR}${PREFIX}/lib/${PYTHON_VERSION}
	${LN} -s '../${SEABIN}/ccnet-server' ${STAGEDIR}/${PREFIX}/bin/ccnet-server

.include "${.CURDIR}/../seafile-server/Makefile.include"

.include <bsd.port.post.mk>
