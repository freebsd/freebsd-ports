PORTNAME=	fog-aws
PORTVERSION=	3.33.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Module for the 'fog' gem to support Amazon Web Services
WWW=		https://github.com/fog/fog-aws

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-base6402>=0.2.0<0.4:converters/rubygem-base6402 \
		rubygem-fog-core-gitlab>=2.6<3:devel/rubygem-fog-core-gitlab \
		rubygem-fog-json-gitlab>=1.1<2:devel/rubygem-fog-json-gitlab \
		rubygem-fog-xml-gitlab>=0.1<1:textproc/rubygem-fog-xml-gitlab

USES=		gem

NO_ARCH=	yes

post-install:
	${RM} ${STAGEDIR}${PREFIX}/bin/console ${STAGEDIR}${PREFIX}/bin/setup

.include <bsd.port.mk>
