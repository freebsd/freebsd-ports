# Ports collection makefile for:	p5-WWW-Scraper-ISBN-Amazon_Driver
# Date created:			Nov 8, 2005
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Scraper-ISBN-Amazon_Driver
PORTVERSION=	0.15
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search driver for the (US) Amazon online catalog

BUILD_DEPENDS=	p5-WWW-Scraper-ISBN>=0.25:${PORTSDIR}/www/p5-WWW-Scraper-ISBN \
		p5-WWW-Scraper-ISBN-Driver>=0.18:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Driver \
		p5-WWW-Mechanize>0:${PORTSDIR}/www/p5-WWW-Mechanize \
		p5-Template-Extract>0:${PORTSDIR}/textproc/p5-Template-Extract
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	WWW::Scraper::ISBN::AmazonUK_Driver.3 \
	WWW::Scraper::ISBN::AmazonUS_Driver.3

.include <bsd.port.mk>
