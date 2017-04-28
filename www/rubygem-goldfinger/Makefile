# $FreeBSD$

PORTNAME=	goldfinger
PORTVERSION=	1.2.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	jrm@FreeBSD.org
COMMENT=	Webfinger utility for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.4:www/rubygem-addressable \
		rubygem-http>=2.0:www/rubygem-http \
		rubygem-nokogiri>=1.6:textproc/rubygem-nokogiri

NO_ARCH=	yes

USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
