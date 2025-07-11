PORTNAME=	tpm-key_attestation
PORTVERSION=	0.14.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	TPM Key Attestation verifier
WWW=		https://github.com/cedarcode/tpm-key_attestation

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	rubygem-bindata>=2.4<3:devel/rubygem-bindata \
		rubygem-openssl>2.0:security/rubygem-openssl \
		rubygem-openssl-signature_algorithm>=1.0<2:security/rubygem-openssl-signature_algorithm

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
