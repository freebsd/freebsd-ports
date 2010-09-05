# New ports collection makefile for:	p5-Chemistry-File-VRML
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-File-VRML
PORTVERSION=	0.10
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	../../authors/id/I/IT/ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Generate VRML models for molecules

BUILD_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol
RUN_DEPENDS=	${SITE_PERL}/Chemistry/Mol.pm:${PORTSDIR}/science/p5-Chemistry-Mol

MAN3=	Chemistry::File::VRML.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
