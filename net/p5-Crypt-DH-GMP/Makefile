# New ports collection makefile for:  Crypt-DH-GMP
# Date created: 04 February 2010
# Whom: andrey@kostenko.name
#
# $FreeBSD$

PORTNAME=	Crypt-DH-GMP
PORTVERSION=	0.00009
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Crypt::DH Using GMP Directly

BUILD_DEPENDS=	p5-Devel-CheckLib>=0:${PORTSDIR}/devel/p5-Devel-CheckLib \
		p5-Devel-PPPort>=3.19:${PORTSDIR}/devel/p5-Devel-PPPort \
		p5-ExtUtils-ParseXS>=2.21:${PORTSDIR}/devel/p5-ExtUtils-ParseXS
LIB_DEPENDS=	gmp.10:${PORTSDIR}/math/gmp

MAKE_JOBS_UNSAFE=	yes

post-patch:
	${REINPLACE_CMD} -e 's#%%LOCALBASE%%#${LOCALBASE}#g' ${WRKSRC}/Makefile.PL

PERL_CONFIGURE=	YES
MAN3=	Crypt::DH::GMP.3 \
	Crypt::DH::GMP::Compat.3

.include <bsd.port.mk>
