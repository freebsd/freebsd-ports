# New ports collection makefile for:	p5-WWW-Search-Google
# Date created:				8 July 2001
# Whom:					Tom Hukins <tom@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-Google
PORTVERSION=	2.21
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW/JSMYSER
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search

BROKEN=		'Port no longer returns search results from Google'

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		WWW::Search::Google.3

.include <bsd.port.mk>
