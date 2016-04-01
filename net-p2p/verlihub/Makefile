# Created by: Bill Cadwallader <hurbold@yahoo.com>
# $FreeBSD$

PORTNAME=	verlihub
DISTVERSION=	0.9.8e-r2
PORTREVISION=	6
PORTEPOCH=	1
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/Verlihub/${DISTVERSION}

MAINTAINER=	me@skylord.ru
COMMENT=	Direct Connect protocol server (Hub)

# XXX: Actually, bash isn't required for building,
# but otherwise configure script would pick the wrong path
BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libGeoIP.so:net/GeoIP \
		libpcre.so:devel/pcre
RUN_DEPENDS=	bash:shells/bash

LIBS+=		-L${LOCALBASE}/lib
USE_RC_SUBR=	verlihub
USES=		libtool
USE_MYSQL=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_OPENSSL=	yes
SUB_FILES+=	pkg-message

post-patch:
	@${REINPLACE_CMD} -e 's|for libpath in /|for libpath in ${PREFIX} /|g' ${WRKSRC}/config_geoip

.include <bsd.port.mk>
