# $FreeBSD$

PORTNAME=	goldfinger
DISTVERSION=	2.0.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Webfinger utility for Ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.5:www/rubygem-addressable \
		rubygem-http>=2.2:www/rubygem-http \
		rubygem-nokogiri>=1.8:textproc/rubygem-nokogiri \
		rubygem-oj>=3.0:devel/rubygem-oj

NO_ARCH=	yes

USES=		gem
USE_RUBY=	yes

.include <bsd.port.mk>
