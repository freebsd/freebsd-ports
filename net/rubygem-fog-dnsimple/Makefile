PORTNAME=	fog-dnsimple
PORTVERSION=	3.0.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support DNSimple
WWW=		https://github.com/fog/fog-dnsimple

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-dnsimple>=13.0<14:net/rubygem-dnsimple \
		rubygem-fog-core>=2.5<3:devel/rubygem-fog-core

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
