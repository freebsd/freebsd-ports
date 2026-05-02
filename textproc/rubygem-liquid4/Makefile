PORTNAME=	liquid
PORTVERSION=	4.0.4
PORTREVISION=	1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	4

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Library for rendering safe templates
WWW=		https://shopify.github.io/liquid/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^4\.

.include <bsd.port.pre.mk>

.if ${RUBY_VER} >= 4.0
RUN_DEPENDS+=	rubygem-bigdecimal>=0:math/rubygem-bigdecimal
.endif

.include <bsd.port.post.mk>
