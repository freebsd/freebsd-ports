# New ports collection makefile for:	p5-MARC-Lint
# Date created:				31 May 2007
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	MARC-Lint
PORTVERSION=	1.44
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	demon@FreeBSD.org
COMMENT=	A mechanism for validating MARC records

BUILD_DEPENDS=	${SITE_PERL}/MARC/Record.pm:${PORTSDIR}/textproc/p5-MARC-Record \
		p5-Business-ISBN>=2.03:${PORTSDIR}/misc/p5-Business-ISBN
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN1=		marclint.1
MAN3=		MARC::Lint.3 MARC::Lint::CodeData.3

PERL_CONFIGURE=	yes

.include <bsd.port.mk>
