PORTNAME=	faraday-typhoeus
PORTVERSION=	1.1.0
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Faraday adapter for Typhoeus
WWW=		https://github.com/dleavitt/faraday-typhoeus

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab \
		rubygem-typhoeus-gitlab>=1.4<2:www/rubygem-typhoeus-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
