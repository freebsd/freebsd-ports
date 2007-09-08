# New ports collection makefile for:	textproc/p5-XML-Atom-SimpleFeed
# Date created:				16 October 2005
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	XML-Atom-SimpleFeed
PORTVERSION=	0.8
CATEGORIES=	textproc perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	XML
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	XML::Atom::SimpleFeed - Generate simple Atom syndication feeds

BUILD_DEPENDS=	${SITE_PERL}/Carp/Clan.pm:${PORTSDIR}/devel/p5-Carp-Clan
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	5.8.0+

MAN3=	XML::Atom::SimpleFeed.3

.include <bsd.port.mk>
