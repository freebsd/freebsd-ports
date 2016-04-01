# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-Scraper-ISBN-Amazon_Driver
PORTVERSION=	0.41
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Search driver for the (US) Amazon online catalog

LICENSE=	ART20

BUILD_DEPENDS=	p5-WWW-Mechanize>=1.60:www/p5-WWW-Mechanize \
		p5-WWW-Scraper-ISBN>=1:www/p5-WWW-Scraper-ISBN
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-JSON>=0:converters/p5-JSON

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
