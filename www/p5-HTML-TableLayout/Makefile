# New ports collection makefile for:	p5-HTML-TableLayout
# Version required:		1.001008
# Date Created:			01 February 2000
# Whom:				Dmitry Sivachenko <dima@Chg.RU>
#
# $FreeBSD$
#

DISTNAME=       HTML-TableLayout-1.001008
PKGNAME=        p5-HTML-TableLayout-1.001008
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML

MAINTAINER=	dima@Chg.RU

USE_PERL5=	yes

MAN3=		HTML::TableLayout.3

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
