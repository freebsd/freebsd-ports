# New ports collection makefile for:	www/p5-Feed-Find
# Date created:				28 July 2005
# Whom:					Lars Thegler <lth@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Feed-Find
PORTVERSION=	0.05
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../by-authors/id/B/BT/BTROTT
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	Syndication feed auto-discovery

BUILD_DEPENDS=	${SITE_PERL}/URI.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/HTML/Parser.pm:${PORTSDIR}/www/p5-HTML-Parser \
		${SITE_PERL}/LWP.pm:${PORTSDIR}/www/p5-libwww \
		${SITE_PERL}/Class/ErrorHandler.pm:${PORTSDIR}/devel/p5-Class-ErrorHandler
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_MODBUILD=	yes

MAN3=	Feed::Find.3

.include <bsd.port.pre.mk>
.if ${PERL_LEVEL} < 500600
IGNORE=	requires Perl 5.6 or newer. Install lang/perl5 or lang/perl5.8, and try again
.endif
.include <bsd.port.post.mk>
