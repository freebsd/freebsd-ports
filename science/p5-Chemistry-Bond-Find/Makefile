# New ports collection makefile for:	p5-Chemistry-Bond-Find
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Bond-Find
PORTVERSION=	0.23
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Detect bonds in a molecule and assign formal bond orders

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol

MAN3=	Chemistry::Bond::Find.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
