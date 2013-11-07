# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-Scraper-ISBN
PORTVERSION=	0.29
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieving information about books by ISBN number

BUILD_DEPENDS=	p5-WWW-Scraper-ISBN-Driver>=0.20:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Driver \
		p5-WWW-Scraper-ISBN-Record>=0.19:${PORTSDIR}/www/p5-WWW-Scraper-ISBN-Record
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
