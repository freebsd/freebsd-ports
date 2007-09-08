# ex:ts=8
# Ports collection makefile for:	p5-WWW-Scraper-ISBN
# Date created:			Nov 8, 2005
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Scraper-ISBN
PORTVERSION=	0.25
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieving information about books by ISBN number

BUILD_DEPENDS=	${SITE_PERL}/WWW/Scraper/ISBN/Record.pm:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Record
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	YES

MAN3=	WWW::Scraper::ISBN.3

.include <bsd.port.mk>
