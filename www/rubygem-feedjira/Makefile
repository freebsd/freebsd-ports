# Created by: Steve Wills <swills@FreeBSD.org>
# $FreeBSD$

PORTNAME=	feedjira
PORTVERSION=	2.0.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Feed fetching and parsing library

LICENSE=	MIT

RUN_DEPENDS=	rubygem-faraday>=0.9:${PORTSDIR}/www/rubygem-faraday \
		rubygem-faraday_middleware>=0.9:${PORTSDIR}/www/rubygem-faraday_middleware \
		rubygem-loofah>=2.0:${PORTSDIR}/textproc/rubygem-loofah \
		rubygem-sax-machine>=1.0:${PORTSDIR}/textproc/rubygem-sax-machine

NO_ARCH=	yes
USE_RUBY=	yes
USE_RUBYGEMS=	yes
RUBYGEM_AUTOPLIST=	yes

.include <bsd.port.mk>
