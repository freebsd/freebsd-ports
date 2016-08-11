# $FreeBSD$

PORTNAME=	haml-rails
PORTVERSION=	0.4
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Haml generator for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack>=3.1:www/rubygem-actionpack \
		rubygem-activesupport>=3.1:devel/rubygem-activesupport \
		rubygem-haml>=3.1:www/rubygem-haml \
		rubygem-railties>=3.1:www/rubygem-railties

PORTSCOUT=	limit:0.4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
