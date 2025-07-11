PORTNAME=	webauthn
PORTVERSION=	3.4.1
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	WebAuthn ruby server library
WWW=		https://github.com/cedarcode/webauthn-ruby

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-android_key_attestation>=0.3.0<0.4:security/rubygem-android_key_attestation \
		rubygem-bindata>=2.4<3:devel/rubygem-bindata \
		rubygem-cbor>=0.5.9<0.6:devel/rubygem-cbor \
		rubygem-cose>=1.1<2:security/rubygem-cose \
		rubygem-openssl>=2.2:security/rubygem-openssl \
		rubygem-safety_net_attestation>=0.4.0<0.5:security/rubygem-safety_net_attestation \
		rubygem-tpm-key_attestation>=0.14.0<0.15:security/rubygem-tpm-key_attestation

USES=		gem

NO_ARCH=	yes

.include <bsd.port.mk>
