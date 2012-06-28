# New ports collection makefile for:	p5-Chemistry-Ring
# Date created:		2010-03-10
# Whom:			Steve Wills <steve@mouf.net>
#
# $FreeBSD$
#

PORTNAME=	Chemistry-Ring
PORTVERSION=	0.20
CATEGORIES=	science perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:ITUB
PKGNAMEPREFIX=	p5-

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Represent a ring as a substructure of a molecule

BUILD_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Statistics-Regression>=0:${PORTSDIR}/math/p5-Statistics-Regression
RUN_DEPENDS=	p5-Chemistry-Mol>=0:${PORTSDIR}/science/p5-Chemistry-Mol \
		p5-Statistics-Regression>=0:${PORTSDIR}/math/p5-Statistics-Regression

MAN3=	Chemistry::Ring.3 Chemistry::Ring::Find.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
