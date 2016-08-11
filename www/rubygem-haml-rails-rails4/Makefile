# $FreeBSD$

PORTNAME=	haml-rails
PORTVERSION=	0.9.0
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-rails4

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Haml generator for Rails

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-actionpack4>=4.0.1:www/rubygem-actionpack4 \
		rubygem-activesupport4>=4.0.1:devel/rubygem-activesupport4 \
		rubygem-haml>=4.0.6:www/rubygem-haml \
		rubygem-html2haml>=1.0.1:www/rubygem-html2haml \
		rubygem-railties4>=4.0.1:www/rubygem-railties4

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
