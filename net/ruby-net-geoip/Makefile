# New ports collection makefile for:	ruby-net-geoip
# Date created:		2002-10-08
# Whom:			Sean Chittenden <seanc@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	net-geoip
PORTVERSION=	0.05
CATEGORIES=	net ruby
MASTER_SITES=	http://www.rubynet.org/modules/net/geoip/
PKGNAMEPREFIX=	${RUBY_PKGNAMEPREFIX}
DIST_SUBDIR=	ruby

MAINTAINER=	seanc@FreeBSD.org

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		GeoIP.2:${PORTSDIR}/net/GeoIP

USE_BZIP2=      yes
USE_RUBY=	yes
USE_RUBY_EXTCONF=	yes
INSTALL_TARGET=	site-install

DOCS=	README

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${RUBY_MODDOCDIR}
.for f in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${RUBY_MODDOCDIR}/
.endfor
.endif

.include <bsd.port.mk>
