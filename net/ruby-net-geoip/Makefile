# Created by: Sean Chittenden <seanc@FreeBSD.org>
# $FreeBSD$

PORTNAME=	net-geoip
PORTVERSION=	0.07
CATEGORIES=	net ruby geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Ruby extension that wraps around libGeoIP

BUILD_DEPENDS=	GeoIP>=1.4.6:${PORTSDIR}/net/GeoIP
LIB_DEPENDS=	libGeoIP.so:${PORTSDIR}/net/GeoIP

USES=		iconv
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=	site-install

DOCS=	README

post-install:
	@${MKDIR} ${STAGEDIR}${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${RUBY_MODDOCDIR}/
.endfor

.include <bsd.port.mk>
