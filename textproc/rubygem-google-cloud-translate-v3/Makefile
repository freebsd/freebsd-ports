PORTNAME=	google-cloud-translate-v3
PORTVERSION=	1.5.2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby Client for the Cloud Translation V3 API
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-translate-v3/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-translate-v3 \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=1.0<2:devel/rubygem-gapic-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors \
		rubygem-google-cloud-location>=1.0<2:net/rubygem-google-cloud-location \
		rubygem-google-iam-v1>=1.3<2:devel/rubygem-google-iam-v1

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
