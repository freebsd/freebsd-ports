# Created by: andrey@kostenko.name
# $FreeBSD$

PORTNAME=	Crypt-DH-GMP
PORTVERSION=	0.00011
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Crypt::DH Using GMP Directly

BUILD_DEPENDS=	p5-Devel-CheckLib>=0.40:${PORTSDIR}/devel/p5-Devel-CheckLib
LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp
TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

MAKE_JOBS_UNSAFE=	yes
USES=		perl5
USE_PERL5=	configure

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
