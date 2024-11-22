PORTNAME=	faraday-retry
PORTVERSION=	2.2.1
CATEGORIES=	www rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Catch exceptions and retries each request a limited number of times
WWW=		https://github.com/lostisland/faraday-retry

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday-gitlab>=2.0<3:www/rubygem-faraday-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
