# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-cloud-translate
PORTVERSION=	3.2.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Translation API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.5<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-translate-v2>=0.0<1:textproc/rubygem-google-cloud-translate-v2 \
		rubygem-google-cloud-translate-v3>=0.0<1:textproc/rubygem-google-cloud-translate-v3

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
