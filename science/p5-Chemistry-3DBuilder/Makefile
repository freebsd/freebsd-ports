# New ports collection makefile for:	p5-Chemistry-3DBuilder
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net
#
# $FreeBSD$
#

PORTNAME=	Chemistry-3DBuilder
PORTVERSION=	0.10
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generate 3D coordinates from a connection table

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/File/SMARTS.pm:${PORTSDIR}/science/p5-Chemistry-File-SMARTS \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords \
		${SITE_PERL}/Math/VectorReal.pm:${PORTSDIR}/math/p5-Math-VectorReal
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/File/SMILES.pm:${PORTSDIR}/science/p5-Chemistry-File-SMILES \
		${SITE_PERL}/Chemistry/File/SMARTS.pm:${PORTSDIR}/science/p5-Chemistry-File-SMARTS \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/InternalCoords.pm:${PORTSDIR}/science/p5-Chemistry-InternalCoords \
		${SITE_PERL}/Math/VectorReal.pm:${PORTSDIR}/math/p5-Math-VectorReal

PERL_CONFIGURE=	yes

MAN3=	Chemistry::3DBuilder.3

.include <bsd.port.mk>
