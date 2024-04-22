PORTNAME=	google-cloud-compute-v1
PORTVERSION=	2.6.0
CATEGORIES=	net rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Ruby Client for the Google Cloud Compute V1 API
WWW=		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common>=0.20.0<2.0:devel/rubygem-gapic-common \
		rubygem-google-cloud-common>=1.0<2:devel/rubygem-google-cloud-common \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
