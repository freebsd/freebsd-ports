# Ports collection makefile for:	p5-WWW-Scraper-ISBN-ORA_Driver
# Date created:			Nov 8, 2005
# Whom:				Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
#
# $FreeBSD$
#

PORTNAME=	WWW-Scraper-ISBN-ORA_Driver
PORTVERSION=	0.08
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	WWW
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search driver for O'Reilly & Associates's online catalog

RUN_DEPENDS=	${SITE_PERL}/WWW/Scraper/ISBN.pm:${PORTSDIR}/www/p5-WWW-Scraper-ISBN \
		${SITE_PERL}/WWW/Scraper/ISBN/Record.pm:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Record \
		${SITE_PERL}/WWW/Scraper/ISBN/Driver.pm:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Driver \
		${SITE_PERL}/WWW/Mechanize.pm:${PORTSDIR}/www/p5-WWW-Mechanize \
		${SITE_PERL}/Template/Extract.pm:${PORTSDIR}/textproc/p5-Template-Extract
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		WWW::Scraper::ISBN::ORA_Driver.3

.include <bsd.port.mk>
