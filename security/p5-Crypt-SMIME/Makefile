# $FreeBSD: head/security/p5-Crypt-SMIME/Makefile 379948 2015-02-25 19:07:59Z adamw $

PORTNAME=	Crypt-SMIME
PORTVERSION=	0.15
PORTREVISION=	3
CATEGORIES=	security perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	S/MIME message signing, verification, encryption and decryption

LICENSE=	ART10

RUN_DEPENDS=	p5-ExtUtils-CChecker>=0:${PORTSDIR}/devel/p5-ExtUtils-CChecker \
		p5-ExtUtils-PkgConfig>=0:${PORTSDIR}/devel/p5-ExtUtils-PkgConfig
BUILD_DEPENDS=	${RUN_DEPENDS}
TEST_DEPENDS=	p5-Taint-Util>=0:${PORTSDIR}/devel/p5-Taint-Util \
		p5-Test-Dependencies>=0:${PORTSDIR}/devel/p5-Test-Dependencies \
		p5-Test-Exception>=0:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Pod>=0:${PORTSDIR}/devel/p5-Test-Pod \
		p5-Test-Pod-Coverage>=0:${PORTSDIR}/devel/p5-Test-Pod-Coverage \
		p5-Test-Taint>=0:${PORTSDIR}/devel/p5-Test-Taint

USES=		perl5
USE_OPENSSL=	yes
WITH_OPENSSL_PORT?=	yes
USE_PERL5=	configure

post-stage:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Crypt/SMIME/SMIME.so

.include <bsd.port.mk>
