# $FreeBSD$

PORTNAME=	ccnet-client
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAFILE_CLIENT_VER}
PORTREVISION=	1
CATEGORIES=	net-mgmt devel

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	valac:lang/vala
LIB_DEPENDS=	libsearpc.so:devel/libsearpc \
		libsqlite3.so:databases/sqlite3 \
		libuuid.so:misc/e2fsprogs-libuuid \
		libevent.so:devel/libevent \
		libjansson.so:devel/jansson

USES=		autoreconf libtool localbase pathfix pkgconfig \
		python:-2.7 ssl
USE_GNOME=	glib20
USE_LDCONFIG=	yes
USE_OPENLDAP=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_PROJECT=	ccnet

CONFLICTS=	ccnet-server-[0-9]*

CONFIGURE_ENV=	SSL_CFLAGS="${OPENSSLINC}" SSL_LIBS="-L${OPENSSLLIB} -lssl -lcrypto"
GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	NLS

NLS_USES=	gettext

.include "${.CURDIR}/../seafile-client/Makefile.include"

.include <bsd.port.mk>
