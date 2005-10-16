# New ports collection makefile for:	textproc/p5-XML-Atom-SimpleFeed
# Date created:				16 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-SimpleFeed
PORTVERSION=	0.7
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	XML::Atom::SimpleFeed - Generate simple Atom syndication feeds

BUILD_DEPENDS=	${SITE_PERL}/XML/Simple.pm:${PORTSDIR}/textproc/p5-XML-Simple
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	XML::Atom::SimpleFeed.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=		Port requires perl 5.6.0 or later. Install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
