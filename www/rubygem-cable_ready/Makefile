PORTNAME=	cable_ready
PORTVERSION=	5.0.6
PORTREVISION=	1
CATEGORIES=	www rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Out-of-Band Server Triggered DOM Operations
WWW=		https://cableready.stimulusreflex.com/ \
		https://github.com/stimulusreflex/cable_ready

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-actionpack81>=5.2:www/rubygem-actionpack81 \
		rubygem-actionview81>=5.2:devel/rubygem-actionview81 \
		rubygem-activesupport81>=5.2:devel/rubygem-activesupport81 \
		rubygem-observer>=0.1<1:devel/rubygem-observer \
		rubygem-railties81>=5.2:www/rubygem-railties81 \
		rubygem-thread-local>=1.1.0:devel/rubygem-thread-local

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
