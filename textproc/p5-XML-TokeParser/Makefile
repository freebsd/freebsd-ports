# New ports collection makefile for:	XML-TokeParser
# Date created:		10 April 2010
# Whom:			Mike Bristow <mike@urgle.com>
#
# $FreeBSD$
#

PORTNAME=	XML-TokeParser
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN/XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mike@urgle.com
COMMENT=	Simplified interface to XML::Parser

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::TokeParser.3

.include <bsd.port.mk>
