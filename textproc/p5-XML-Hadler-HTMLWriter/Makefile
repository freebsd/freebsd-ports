# New ports collection makefile for:	XML::Handler::HTMLWriter
# Date created:				Oct 13th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	XML-Handler-HTMLWriter
PORTVERSION=	2.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	PerlSAX handlers for outputting HTML

RUN_DEPENDS=	p5-XML-SAX-Writer>=0:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		p5-HTML-Parser>=0:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS:=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Handler::HTMLWriter.3

.include <bsd.port.mk>
