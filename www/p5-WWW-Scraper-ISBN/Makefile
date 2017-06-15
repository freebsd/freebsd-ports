# Created by: Ying-Chieh Liao <ijliao@csie.nctu.edu.tw>
# $FreeBSD$

PORTNAME=	WWW-Scraper-ISBN
PORTVERSION=	1.03
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Retrieving information about books by ISBN number

LICENSE=	ART20

BUILD_DEPENDS=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable
RUN_DEPENDS=	p5-Module-Pluggable>=0:devel/p5-Module-Pluggable

CONFLICTS_INSTALL=	p5-WWW-Scraper-ISBN-Driver-[0-9]* p5-WWW-Scraper-ISBN-Record-[0-9]*

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
