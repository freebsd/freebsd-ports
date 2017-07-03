# $FreeBSD$

PORTNAME=	ccnet-server
PORTVERSION=	${SEAFILE_VER}
DISTVERSIONPREFIX=	v
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

CONFLICT=	ccnet-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		autoreconf gettext libtool localbase mysql:client \
       		pathfix pgsql pkgconfig python:-2.7 shebangfix ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ldap
INSTALL_TARGET=	install-strip

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

.include <bsd.port.mk>
