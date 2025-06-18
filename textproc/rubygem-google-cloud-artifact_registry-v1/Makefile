PORTNAME=	google-cloud-artifact_registry-v1
PORTVERSION=	0.11.0
PORTREVISION=	2
CATEGORIES=	textproc rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Manages artifacts on Google infrastructure
WWW=		https://googleapis.github.io/google-cloud-ruby/docs/ \
		https://github.com/googleapis/google-cloud-ruby

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.md

RUN_DEPENDS=	rubygem-gapic-common-gitlab>=0.20.0<2:devel/rubygem-gapic-common-gitlab \
		rubygem-google-cloud-errors>=1.0<2:net/rubygem-google-cloud-errors \
		rubygem-google-cloud-location-gitlab>=0.4<2:net/rubygem-google-cloud-location-gitlab \
		rubygem-grpc-google-iam-v1-gitlab>=1.1<2:devel/rubygem-grpc-google-iam-v1-gitlab

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
