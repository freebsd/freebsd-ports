# New ports collection makefile for:	p5-HTML-QuickCheck
# Date created:				October 20th 1996
# Whom:	      				James FitzGibbon <jfitz@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	p5-HTML-QuickCheck
PORTVERSION= 	1.0b1
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	HTML
DISTNAME=	HTML-QuickCheck-1.0b1

MAINTAINER=	jfitz@FreeBSD.org

USE_PERL5=	YES

MAN3=		HTML::QuickCheck.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

do-configure:
		@ cd ${WRKSRC}; ${SETENV} ${MAKE_ENV} ${PERL5} Makefile.PL

.include <bsd.port.mk>
