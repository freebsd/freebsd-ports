# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	signet
PORTVERSION=	0.8.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	OAuth 1.0 / OAuth 2.0 implementation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.3:www/rubygem-addressable \
		rubygem-faraday>=0.9:www/rubygem-faraday \
		rubygem-jwt>=1.5:www/rubygem-jwt \
		rubygem-multi_json>=1.10:devel/rubygem-multi_json

NO_ARCH=	yes
USE_RUBY=	yes
USES=		gem

.include <bsd.port.mk>
