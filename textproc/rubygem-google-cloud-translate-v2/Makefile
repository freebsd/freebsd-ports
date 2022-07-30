PORTNAME=	google-cloud-translate-v2
PORTVERSION=	0.4.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Translation V2 API

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday1>=0.17.3<2.0:www/rubygem-faraday1 \
		rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-googleapis-common-protos>=1.3.10<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.0.5<2.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
