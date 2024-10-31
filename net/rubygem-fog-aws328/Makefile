PORTNAME=	fog-aws
PORTVERSION=	3.28.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	328

MAINTAINER=	ruby@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Amazon Web Services
WWW=		https://github.com/fog/fog-aws

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base64>=0.2.0<0.3:converters/rubygem-base64 \
		rubygem-fog-core250>=2.1<3:devel/rubygem-fog-core250 \
		rubygem-fog-json>=1.1<2:devel/rubygem-fog-json \
		rubygem-fog-xml>=0.1<1:textproc/rubygem-fog-xml

USES=		gem

NO_ARCH=	yes

PORTSCOUT=	limit:^3\.28\.

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
