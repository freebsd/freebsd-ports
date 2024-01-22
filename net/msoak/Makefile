PORTNAME=	msoak
DISTVERSION=	0.8
PORTREVISION=	1
CATEGORIES=	net

MAINTAINER=	ports@jpmens.net
COMMENT=	Subscribe to different MQTT brokers and topics simultaneously
WWW=		https://github.com/jpmens/msoak

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libmosquitto.so:net/mosquitto \
		libconfig.so:devel/libconfig

USES=		localbase:ldflags lua:53+
USE_GITHUB=	yes
GH_ACCOUNT=	jpmens

CFLAGS+=	-I${LUA_INCDIR}
LDFLAGS+=	-llua-${LUA_VER} -lmosquitto -lconfig
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" LDFLAGS="${LDFLAGS}" \
		BINDIR=${PREFIX}/bin MANDIR=${PREFIX}/share/man

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/msoak
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/example.* ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
