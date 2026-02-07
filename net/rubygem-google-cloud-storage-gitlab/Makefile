PORTNAME=	google-cloud-storage
PORTVERSION=	1.57.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG
PKGNAMESUFFIX=	-gitlab

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Official library for Google Cloud Storage
WWW=		https://cloud.google.com/ruby/docs/reference/google-cloud-storage/latest/ \
		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby/tree/main/google-cloud-storage \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-digest-crc>=0.4<1:security/rubygem-digest-crc \
		rubygem-google-apis-iamcredentials_v1-gitlab>=0.18<1:devel/rubygem-google-apis-iamcredentials_v1-gitlab \
		rubygem-google-apis-storage_v1-gitlab>=0.42.0<1:devel/rubygem-google-apis-storage_v1-gitlab \
		rubygem-googleauth-gitlab>=1.9<2.0:security/rubygem-googleauth-gitlab \
		rubygem-google-cloud-core-gitlab>=1.6<2:net/rubygem-google-cloud-core-gitlab \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
