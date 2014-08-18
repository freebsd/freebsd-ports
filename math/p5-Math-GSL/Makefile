# Created by: Maxim Sobolev <sobomax@FreeBSD.org>
# $FreeBSD$

PORTNAME=	Math-GSL
PORTVERSION=	0.32
PORTREVISION=	1
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Perl interface to GNU Scientific Library

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-PkgConfig>=0.07720:${PORTSDIR}/devel/p5-PkgConfig
LIB_DEPENDS=	libgsl.so:${PORTSDIR}/math/gsl
TEST_DEPENDS=	p5-Test-Class>=0.12:${PORTSDIR}/devel/p5-Test-Class \
		p5-Test-Exception>=0.21:${PORTSDIR}/devel/p5-Test-Exception \
		p5-Test-Most>=0.31:${PORTSDIR}/devel/p5-Test-Most

USE_PERL5=	modbuild
USES=		perl5

BROKEN_sparc64=		Does not compile on sparc64

.include <bsd.port.mk>
