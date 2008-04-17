# New ports collection makefile for:	XML-Driver-HTML
# Date created:	   22 October 2005
# Whom:		   Dmitry Morozovsky <marck@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Driver-HTML
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	skv@FreeBSD.org
COMMENT=	Perl SAX Driver for non wellformed HTML

BUILD_DEPENDS=	${SITE_PERL}/XML/TreeBuilder.pm:${PORTSDIR}/textproc/p5-XML-TreeBuilder \
		${SITE_PERL}/XML/Handler/YAWriter.pm:${PORTSDIR}/textproc/p5-XML-Handler-YAWriter
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN1=		html2xhtml.1
MAN3=		XML::Driver::HTML.3

.include <bsd.port.mk>
