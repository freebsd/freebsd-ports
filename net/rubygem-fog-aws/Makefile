PORTNAME=	fog-aws
PORTVERSION=	3.33.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Amazon Web Services
WWW=		https://github.com/fog/fog-aws

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0.2<0.4:converters/rubygem-base64 \
		rubygem-fog-core>=2.6<3:devel/rubygem-fog-core \
		rubygem-fog-json>=1.1<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1<1:textproc/rubygem-fog-xml

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
