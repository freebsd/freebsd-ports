# New ports collection makefile for:	p5-Chemistry-File-SLN
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-SLN
PORTVERSION=	0.11
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	SLN linear notation parser/writer

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol \
		${SITE_PERL}/Chemistry/Ring/Find.pm:${PORTSDIR}/science/p5-Chemistry-Ring \
		${SITE_PERL}/Chemistry/Canonicalize.pm:${PORTSDIR}/science/p5-Chemistry-Canonicalize \
		${SITE_PERL}/Chemistry/Bond/Find.pm:${PORTSDIR}/science/p5-Chemistry-Bond-Find \
		${SITE_PERL}/Parse/Yapp/Parse.pm:${PORTSDIR}/devel/p5-Parse-Yapp

MAN3=	Chemistry::File::SLN.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
