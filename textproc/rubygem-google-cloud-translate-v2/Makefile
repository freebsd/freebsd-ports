PORTNAME=	google-cloud-translate-v2
PORTVERSION=	1.0.0
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Translation V2 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-translate-v2/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-translate-v2 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-faraday>=1.0<3.0:www/rubygem-faraday \
		rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-googleapis-common-protos>=1.3.10<2.0:devel/rubygem-googleapis-common-protos \
		rubygem-googleapis-common-protos-types>=1.0.5<2.0:devel/rubygem-googleapis-common-protos-types \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
