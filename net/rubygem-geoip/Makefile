# $FreeBSD$

PORTNAME=	geoip
PORTVERSION=	1.6.4
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Geoip implementation for rubygems

LICENSE=	LGPL21+
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	geoiplookup:net/GeoIP

DEPRECATED=     Uses legacy GeoIP 1 format which no longer works; switch to GeoIP 2 where possible
EXPIRATION_DATE=2019-02-15

REINPLACE_ARGS=	-i ''
NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

PLIST_FILES=	bin/geoip

post-patch:
	@${REINPLACE_CMD} -e '1d' ${WRKSRC}/test/csvORG2dat.py

.include <bsd.port.mk>
