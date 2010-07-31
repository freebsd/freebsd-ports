# New ports collection makefile for:	textproc/p5-XML-Rules
# Date created:				14 October 2008
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Rules
PORTVERSION=	1.10
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Parse XML and specify rules for individual tags

RUN_DEPENDS=	p5-XML-Parser>=2.00:${PORTSDIR}/textproc/p5-XML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	XML::Rules.3

.include <bsd.port.mk>
