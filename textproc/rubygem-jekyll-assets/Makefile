# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jekyll-assets
PORTVERSION=	2.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create javascript/CSS assets for Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-concurrent-ruby>=1.0:devel/rubygem-concurrent-ruby \
		rubygem-extras>=0.2:devel/rubygem-extras \
		rubygem-fastimage>=2.0:graphics/rubygem-fastimage \
		rubygem-jekyll>=3.1:www/rubygem-jekyll \
		rubygem-pathutil>=0.8:devel/rubygem-pathutil \
		rubygem-rack16>=1.6:www/rubygem-rack16 \
		rubygem-sprockets3>=3.3:devel/rubygem-sprockets3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
