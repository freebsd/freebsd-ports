# Created by: Ryan Steinmetz <zi@FreeBSD.org>
# $FreeBSD$

PORTNAME=	jekyll-assets
PORTVERSION=	3.0.12
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Create javascript/CSS assets for Jekyll sites

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-activesupport5>=5.0<6:devel/rubygem-activesupport5 \
		rubygem-execjs>=2.7<3:devel/rubygem-execjs \
		rubygem-extras>=0.2<1:devel/rubygem-extras \
		rubygem-fastimage>=2.0<3:graphics/rubygem-fastimage \
		rubygem-jekyll3>=3.5<4.0:www/rubygem-jekyll3 \
		rubygem-jekyll-sanity>=1.2<2:www/rubygem-jekyll-sanity \
		rubygem-liquid-tag-parser1>=1.0<2:textproc/rubygem-liquid-tag-parser1 \
		rubygem-nokogiri>=1.8<2:textproc/rubygem-nokogiri \
		rubygem-pathutil>=0.16<1:devel/rubygem-pathutil \
		rubygem-sprockets3>=3.3<4.1:devel/rubygem-sprockets3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
