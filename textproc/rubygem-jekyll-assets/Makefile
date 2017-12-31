# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jekyll-assets
PORTVERSION=	3.0.5
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create javascript/CSS assets for Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=5.0:devel/rubygem-activesupport5 \
		rubygem-execjs>=2.7:devel/rubygem-execjs \
		rubygem-extras>=0.2:devel/rubygem-extras \
		rubygem-fastimage>=2.0:graphics/rubygem-fastimage \
		rubygem-jekyll>=3.5:www/rubygem-jekyll \
		rubygem-jekyll-sanity>=1.2:www/rubygem-jekyll-sanity \
		rubygem-liquid-tag-parser>=1.0:textproc/rubygem-liquid-tag-parser \
		rubygem-nokogiri>=1.8:textproc/rubygem-nokogiri \
		rubygem-pathutil>=0.16:devel/rubygem-pathutil \
		rubygem-sprockets3>=3.3:devel/rubygem-sprockets3

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
