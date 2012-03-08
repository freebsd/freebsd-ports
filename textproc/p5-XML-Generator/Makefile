# New ports collection makefile for:	XML::Generator
# Date created:				22 January 2004
# Whom:					Andreas Heil <ah@linux-hq.de>
#
# $FreeBSD$
#

PORTNAME=	XML-Generator
PORTVERSION=	1.04
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ah@linux-hq.de
COMMENT=	A simple Perl module for generating XML documents

BUILD_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM
RUN_DEPENDS=	p5-XML-DOM>=0:${PORTSDIR}/textproc/p5-XML-DOM

TEST_DEPENDS=	p5-Tie-IxHash>=0:${PORTSDIR}/devel/p5-Tie-IxHash

PERL_CONFIGURE=	yes

MAN3=		XML::Generator.3 XML::Generator::DOM.3

.include <bsd.port.mk>
