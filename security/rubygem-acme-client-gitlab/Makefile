PORTNAME=	acme-client
PORTVERSION=	2.0.22
CATEGORIES=	security rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Client for the ACME protocol
WWW=		https://github.com/unixcharles/acme-client

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-base6402>=0.2.0<0.3:converters/rubygem-base6402 \
		rubygem-faraday-gitlab>=1.0<3.0.0:www/rubygem-faraday-gitlab \
		rubygem-faraday-retry-gitlab>=1.0<3.0.0:www/rubygem-faraday-retry-gitlab

USES=		gem shebangfix

SHEBANG_FILES=	bin/setup

NO_ARCH=	yes

.include <bsd.port.mk>
