PORTNAME=	liquid
PORTVERSION=	5.8.7
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering safe templates
WWW=		https://shopify.github.io/liquid/ \
		https://github.com/Shopify/liquid

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal \
		rubygem-strscan>=3.1.1:devel/rubygem-strscan

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
