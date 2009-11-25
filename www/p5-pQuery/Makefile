# New ports collection makefile for:	www/p5-pQuery
# Date created:				25 November 2009
# Whom:					Anton Berezin <tobez@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pQuery
PORTVERSION=	0.07
CATEGORIES=	www perl5
MASTER_SITES=	CPAN/../../authors/id/I/IN/INGY/
PKGNAMEPREFIX=	p5-

MAINTAINER=	tobez@FreeBSD.org
COMMENT=	Perl Port of jQuery.js

BUILD_DEPENDS=	p5-HTML-Tree>=0:${PORTSDIR}/www/p5-HTML-Tree
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	pQuery.3 \
	pQuery::DOM.3

.include <bsd.port.mk>
