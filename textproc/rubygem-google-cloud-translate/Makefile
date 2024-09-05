PORTNAME=	google-cloud-translate
PORTVERSION=	3.6.1
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Translation API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-translate/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-translate \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-google-cloud-translate-v2>=0.0<2.0:textproc/rubygem-google-cloud-translate-v2 \
		rubygem-google-cloud-translate-v3>=0.11<2.0:textproc/rubygem-google-cloud-translate-v3

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
