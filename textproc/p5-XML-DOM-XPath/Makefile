# New ports collection makefile for:	textproc/p5-XML-DOM-XPath
# Date created:				8 September 2005
# Whom:					Mauricio Herrera Cuadra <mauricio@arareko.net>
#
# $FreeBSD$
#

PORTNAME=	XML-DOM-XPath
PORTVERSION=	0.13
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	mauricio@arareko.net
COMMENT=	Adds XPath support to XML::DOM, using XML::XPath engine

RUN_DEPENDS=	${SITE_PERL}/XML/DOM.pm:${PORTSDIR}/textproc/p5-XML-DOM \
		${SITE_PERL}/XML/XPathEngine.pm:${PORTSDIR}/textproc/p5-XML-XPathEngine

PERL_CONFIGURE=	yes

MAN3=	XML::DOM::XPath.3

.include <bsd.port.mk>
