# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	acme-client
PORTVERSION=	2.0.10
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Client for the ACME protocol

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-faraday>=1.0<3.0.0:www/rubygem-faraday \
		rubygem-faraday-retry>=1.0:www/rubygem-faraday-retry

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	bin/setup

.include <bsd.port.mk>
