# $FreeBSD$

PORTNAME=	ccnet-client
PORTVERSION=	${SEAFILE_CLIENT_VER}
DISTVERSIONPREFIX=	v
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libsqlite3.so:databases/sqlite3 \
		libzdb.so:databases/libzdb \
		libuuid.so:misc/e2fsprogs-libuuid \
		libevent.so:devel/libevent \
		libjansson.so:devel/jansson

CONFLICTS=	ccnet-server-[0-9]*

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	ccnet

USES=		autoreconf gettext libtool localbase pathfix pkgconfig \
		python:-2.7 ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--enable-ldap
INSTALL_TARGET=	install-strip

.include "${.CURDIR}/../seafile-client/Makefile.include"

.include <bsd.port.mk>
