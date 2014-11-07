# $FreeBSD$

PORTNAME=	Crypt-SMIME
PORTVERSION=	0.15
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	S/MIME message signing, verification, encryption and decryption

LICENSE=	ART10

RUN_DEPENDS=	p5-ExtUtils-CChecker>=0:${PORTSDIR}/devel/p5-ExtUtils-CChecker \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		${LOCALBASE}/lib/libcrypto.so:${PORTSDIR}/security/openssl
BUILD_DEPENDS=	${RUN_DEPENDS}

USES=		perl5
USE_OPENSSL=	yes
USE_PERL5=	configure

post-stage:
	${STRIP_CMD} ${STAGEDIR}${SITE_PERL}/${PERL_ARCH}/auto/Crypt/SMIME/SMIME.so

.include <bsd.port.mk>
