# New ports collection makefile for:	p5-Chemistry-File-MDLMol
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-MDLMol
PORTVERSION=	0.21
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	MDL molfile reader/write

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring

MAN3=	Chemistry::File::MDLMol.3 Chemistry::File::SDF.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
