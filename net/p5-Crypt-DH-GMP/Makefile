# New ports collection makefile for:  Crypt-DH-GMP
# Date created: 04 February 2010
# Whom: andrey@kostenko.name
#
# $FreeBSD$
#

PORTNAME=	Crypt-DH-GMP
PORTVERSION=	0.00010
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Crypt::DH Using GMP Directly

BUILD_DEPENDS=	p5-Devel-CheckLib>=0.40:${PORTSDIR}/devel/p5-Devel-CheckLib
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

TEST_DEPENDS=	p5-Test-Requires>=0:${PORTSDIR}/devel/p5-Test-Requires

MAKE_JOBS_UNSAFE=	yes
PERL_CONFIGURE=	yes

MAN3=		Crypt::DH::GMP.3 \
		Crypt::DH::GMP::Compat.3

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/Makefile.PL

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 501001
BUILD_DEPENDS+=	p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort
.endif

.if ${PERL_LEVEL} < 501200
BUILD_DEPENDS+=	p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
.endif

.include <bsd.port.post.mk>
