# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minima
PORTVERSION=	2.5.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Beautiful, minimal theme for Jekyll

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-jekyll>=3.5<5.0:www/rubygem-jekyll \
		rubygem-jekyll-feed>=0.9<1:textproc/rubygem-jekyll-feed \
		rubygem-jekyll-seo-tag>=2.1<3:www/rubygem-jekyll-seo-tag

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
