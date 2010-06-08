# New ports collection makefile for:	ruby-net-geoip
# Date created:		2002-10-08
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	net-geoip
PORTVERSION=	0.07
CATEGORIES=	net ruby geography
MASTER_SITES=	http://geolite.maxmind.com/download/geoip/api/ruby/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	f3cun3c02@sneakemail.com
COMMENT=	A Ruby extension that wraps around libGeoIP

BUILD_DEPENDS=	GeoIP>=1.4.6:${PORTSDIR}/net/GeoIP
LIB_DEPENDS=	GeoIP.5:${PORTSDIR}/net/GeoIP

USE_ICONV=	yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=	site-install

DOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
