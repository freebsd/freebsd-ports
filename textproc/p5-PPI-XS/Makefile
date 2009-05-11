# New ports collection makefile for:	textproc/p5-PPI-XS
# Date created:				09 May 2007
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	PPI-XS
PORTVERSION=	0.901
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	PPI
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	XS acceleration for the PPI perl parser

RUN_DEPENDS=	p5-PPI>=1.000:${PORTSDIR}/textproc/p5-PPI
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	PPI::XS.3

.include <bsd.port.mk>
