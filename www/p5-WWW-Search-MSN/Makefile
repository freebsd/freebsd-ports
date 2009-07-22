# New ports collection makefile for:	p5-WWW-Search-MSN
# Date created:		2006-07-14
# Whom:			Gea-Suan Lin <gslin@gslin.org>
#
# $FreeBSD$
#

PORTNAME=	WWW-Search-MSN
PORTVERSION=	0.0106
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Backend for searching search.msn.com

BUILD_DEPENDS=	${SITE_PERL}/HTML/TreeBuilder.pm:${PORTSDIR}/www/p5-HTML-Tree \
		${SITE_PERL}/WWW/Search.pm:${PORTSDIR}/www/p5-WWW-Search
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Search::MSN.3

.include <bsd.port.mk>
