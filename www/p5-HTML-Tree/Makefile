# New ports collection makefile for:	p5-HTML-Tree
# Date created:			3 January 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

PORTNAME=	p5-HTML-Tree
PORTVERSION= 	0.62
CATEGORIES=     www perl5
MASTER_SITES=   ${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
DISTNAME=	HTML-Tree-0.62

MAINTAINER=	dima@Chg.RU

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/HTML/HeadParser.pm:${PORTSDIR}/www/p5-HTML-Parser

USE_PERL5=	YES

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

MAN3=		HTML::Parse.3 HTML::TreeBuilder.3 HTML::AsSubs.3 HTML::Element.3

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
