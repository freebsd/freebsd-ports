# New ports collection makefile for:    p5-HTML-CalendarMonthSimple
# Date created:				May 27 2001
# Whom:	      				vanilla
#
# $FreeBSD$
#

PORTNAME=	HTML-CalendarMonthSimple
PORTVERSION=	1.25
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
PKGNAMEPREFIX=	p5-

MAINTAINER=	erwin@FreeBSD.org
COMMENT=	HTML::CalendarMonthSimple - Perl Module for Generating HTML Calendars

BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/Date/Calc.pm:${PORTSDIR}/devel/p5-Date-Calc
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}
MAN3=		HTML::CalendarMonthSimple.3

.include <bsd.port.mk>
