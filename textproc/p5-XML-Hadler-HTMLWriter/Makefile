# New ports collection makefile for:	XML::Handler::HTMLWriter
# Date created:				Oct 13th 2003
# Whom:					clsung@dragon2.net
#
# $FreeBSD$

PORTNAME=	XML-Handler-HTMLWriter
PORTVERSION=	2.01
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	PerlSAX handlers for outputting HTML

RUN_DEPENDS=	${SITE_PERL}/XML/SAX/Writer.pm:${PORTSDIR}/textproc/p5-XML-SAX-Writer \
		${SITE_PERL}/${PERL_ARCH}/HTML/Entities.pm:${PORTSDIR}/www/p5-HTML-Parser
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		XML::Handler::HTMLWriter.3

.include <bsd.port.mk>
