# New ports collection makefile for:	p5-UML-State
# Date created:				October 15th 2003
# Whom:	      				Cheng-Lung Sung <clsung@dragon2.net>
#
# $FreeBSD$
#

PORTNAME=	UML-State
PORTVERSION=	0.02
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	A perl module that produce simple UML state diagrams

BUILD_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN1=		drawstatexml.pl.1 drawstate.pl.1
MAN3=		UML::drawstate.3 \
		UML::drawstatexml.3 \
		UML::State.3

.include <bsd.port.mk>
