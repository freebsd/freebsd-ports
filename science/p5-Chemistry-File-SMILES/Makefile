# New ports collection makefile for:	p5-Chemistry-File-SMILES
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-SMILES
PORTVERSION=	0.47
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	steve@mouf.net
COMMENT=	SMILES linear notation parser/writer

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/Ring.pm:${PORTSDIR}/science/p5-Chemistry-Ring

MAN3=	Chemistry::File::SMILES.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
