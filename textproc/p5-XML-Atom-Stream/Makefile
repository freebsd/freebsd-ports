# New ports collection makefile for:	p5-XML-Atom-Stream
# Date created:				12 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-Stream
PORTVERSION=	0.11
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	A client interface for AtomStream

RUN_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-Handler-Trees>=0.02:${PORTSDIR}/textproc/p5-XML-Handler-Trees \
		p5-XML-Atom>=0.20:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-XML-LibXML>=1.59:${PORTSDIR}/textproc/p5-XML-LibXML
BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		p5-XML-SAX>=0.12:${PORTSDIR}/textproc/p5-XML-SAX \
		p5-XML-Handler-Trees>=0.02:${PORTSDIR}/textproc/p5-XML-Handler-Trees \
		p5-XML-Atom>=0.20:${PORTSDIR}/textproc/p5-XML-Atom \
		p5-XML-LibXML>=1.59:${PORTSDIR}/textproc/p5-XML-LibXML

MAN3=	XML::Atom::Stream.3

PERL_CONFIGURE=	5.8.5+	# inherited from textproc/p5-XML-Atom

.include <bsd.port.mk>
