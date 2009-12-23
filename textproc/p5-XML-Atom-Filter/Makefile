# New ports collection makefile for:	textproc/p5-XML-Atom-Filter
# Date created:				13 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-Filter
PORTVERSION=	0.07
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy creation of command line Atom processing tools

RUN_DEPENDS=	${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	XML::Atom::Filter.3

.include <bsd.port.mk>
