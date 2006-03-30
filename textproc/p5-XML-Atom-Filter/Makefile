# New ports collection makefile for:	textproc/p5-XML-Atom-Filter
# Date created:				13 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-Filter
PORTVERSION=	0.06
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Easy creation of command line Atom processing tools

RUN_DEPENDS=	${SITE_PERL}/XML/Atom.pm:${PORTSDIR}/textproc/p5-XML-Atom
BUILD_DEPENDS=	${RUN_DEPENDS}
BUILD_DEPENDS+=	${SITE_PERL}/Test/More.pm:${PORTSDIR}/devel/p5-Test-Simple

PERL_CONFIGURE=	yes

MAN3=	XML::Atom::Filter.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500800
IGNORE=		requires perl 5.8.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
