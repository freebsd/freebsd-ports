PORTNAME=	cable_ready
PORTVERSION=	5.0.3
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Out-of-Band Server Triggered DOM Operations
WWW=		https://cableready.stimulusreflex.com/ \
		https://github.com/stimulusreflex/cable_ready

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack71>=5.2:www/rubygem-actionpack71 \
		rubygem-actionview71>=5.2:devel/rubygem-actionview71 \
		rubygem-activesupport71>=5.2:devel/rubygem-activesupport71 \
		rubygem-railties71>=5.2:www/rubygem-railties71 \
		rubygem-thread-local>=1.1.0:devel/rubygem-thread-local

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
