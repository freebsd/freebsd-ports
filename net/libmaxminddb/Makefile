# $FreeBSD$

PORTNAME=	libmaxminddb
DISTVERSION=	1.0.4
CATEGORIES=	net
MASTER_SITES=	https://github.com/maxmind/libmaxminddb/releases/download/${DISTVERSION}/

MAINTAINER=	fullermd@over-yonder.net
COMMENT=	Library for the MaxMind DB file format used for GeoIP2

LICENSE=	APACHE20

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USES=		libtool

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libmaxminddb.so.0.0.7

.include <bsd.port.mk>
