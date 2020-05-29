# $FreeBSD$

PORTNAME=	asana
PORTVERSION=	0.10.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby wrapper for the Asana REST API

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday0>=0.9<1:www/rubygem-faraday0 \
		rubygem-faraday_middleware0>=0.9<1:www/rubygem-faraday_middleware0 \
		rubygem-faraday_middleware-multi_json>=0.0<1:devel/rubygem-faraday_middleware-multi_json \
		rubygem-oauth2>=1.4<2:net/rubygem-oauth2

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
