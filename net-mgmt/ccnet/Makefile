# $FreeBSD$

PORTNAME=	ccnet
PORTVERSION=	3.1.4
PORTREVISION=	1
CATEGORIES=	net-mgmt devel

MAINTAINER=	yan_jingfeng@yahoo.com
COMMENT=	Framework for writing networked applications

LICENSE=	GPLv3

BUILD_DEPENDS=	valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	libsearpc.so:${PORTSDIR}/devel/libsearpc \
		libcrypto.so:${PORTSDIR}/security/openssl \
		libglib-2.0.so:${PORTSDIR}/devel/glib20 \
		libgobject-2.0.so:${PORTSDIR}/devel/glib20 \
		libsqlite3.so:${PORTSDIR}/databases/sqlite3 \
		libzdb.so:${PORTSDIR}/databases/libzdb \
		libuuid.so:${PORTSDIR}/misc/e2fsprogs-libuuid \
		libevent.so:${PORTSDIR}/devel/libevent2 \
		libjansson.so:${PORTSDIR}/devel/jansson

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
GH_TAGNAME=	v3.1.4
GH_COMMIT=	6b55658

USES=		autoreconf libtool pkgconfig pathfix python:2
PATHFIX_MAKEFILEIN=	Makefile.am
USE_LDCONFIG=	yes

CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/event2
LDFLAGS+=	-L${LOCALBASE}/lib -L${LOCALBASE}/lib/event2
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-server
INSTALL_TARGET=	install-strip

WITH_OPENSSL_PORT=	yes
USE_OPENSSL=	yes

WWWDIR=		${PREFIX}/www/haiwen/seafile-server
SEABIN=		${STAGEDIR}${WWWDIR}/seafile/bin

post-install:
	@${MKDIR} ${SEABIN}
	${LN} ${STAGEDIR}${PREFIX}/bin/ccnet-init ${SEABIN}
	${LN} ${STAGEDIR}${PREFIX}/bin/ccnet-server ${SEABIN}

.include <bsd.port.mk>
