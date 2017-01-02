# $FreeBSD$

PORTNAME=	ccnet-client
PORTVERSION=	6.0.1
DISTVERSIONPREFIX=	v
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
		libjansson.so:devel/jansson

CONFLICTS=	ccnet-server-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	ccnet

USES=		autoreconf gettext libtool localbase pathfix pkgconfig \
		python:-2.7 shebangfix ssl
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes
SHEBANG_FILES=	tools/*.py

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ldap
INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1000000
WITH_OPENSSL_PORT=	yes
.endif

.include <bsd.port.mk>
