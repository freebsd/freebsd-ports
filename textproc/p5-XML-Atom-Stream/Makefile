# New ports collection makefile for:	p5-XML-Atom-Stream
# Date created:				12 Jun 2006
# Whom:					Aaron Dalton <aaron@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-Stream
PORTVERSION=	0.03
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	aaron@FreeBSD.org
COMMENT=	A client interface for AtomStream

BUILD_DEPENDS=	${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/XML/SAX.pm:${PORTSDIR}/textproc/p5-XML-SAX \
		${SITE_PERL}/XML/Handler/Trees.pm:${PORTSDIR}/textproc/p5-XML-Handler-Trees \
		${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom
RUN_DEPENDS=	${BUILD_DEPENDS}

MAN3=	XML::Atom::Stream.3

PERL_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500805 # inherited from textproc/p5-XML-Atom
IGNORE=	requires at least Perl 5.8.5 due to dependencies.  Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
