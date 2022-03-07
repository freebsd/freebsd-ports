# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>

PORTNAME=	google-cloud-storage
PORTVERSION=	1.36.1
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Official library for Google Cloud Storage

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-addressable>=2.8<3:www/rubygem-addressable \
		rubygem-digest-crc>=0.4<1:security/rubygem-digest-crc \
		rubygem-google-apis-iamcredentials_v1>=0.1<1:devel/rubygem-google-apis-iamcredentials_v1 \
		rubygem-google-apis-storage_v1>=0.1<1:devel/rubygem-google-apis-storage_v1 \
		rubygem-google-cloud-core>=1.6<2:net/rubygem-google-cloud-core \
		rubygem-googleauth>=0.16.2<2.0:security/rubygem-googleauth \
		rubygem-mini_mime>=1.0<2:mail/rubygem-mini_mime

USES=		gem
USE_RUBY=	yes

NO_ARCH=	yes

.include <bsd.port.mk>
