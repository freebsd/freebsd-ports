# Created by: Matthias Fechner <mfechner@FreeBSD.org>
# $FreeBSD$

PORTNAME=	webauthn
PORTVERSION=	2.4.0
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	WebAuthn ruby server library

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	rubygem-android_key_attestation>=0.3.0:security/rubygem-android_key_attestation \
		rubygem-awrence>=1.1<2:devel/rubygem-awrence \
		rubygem-bindata>=2.4<3:devel/rubygem-bindata \
		rubygem-cbor>=0.5.9<0.6:devel/rubygem-cbor \
		rubygem-cose>=1.1<2:security/rubygem-cose \
		rubygem-openssl>=2.0<3:security/rubygem-openssl \
		rubygem-safety_net_attestation>=0.4.0<0.5:security/rubygem-safety_net_attestation \
		rubygem-securecompare>=1.0<2:security/rubygem-securecompare \
		rubygem-tpm-key_attestation>=0.10.0<0.11:security/rubygem-tpm-key_attestation

USES=		gem shebangfix
USE_RUBY=	yes
SHEBANG_FILES=	script/ci/install-openssl script/ci/install-ruby

NO_ARCH=	yes

.include <bsd.port.mk>
