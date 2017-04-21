# Created by: chinsan <chinsan.tw@gmail.com>
# $FreeBSD$

PORTNAME=	HTML-TableParser
PORTVERSION=	0.42
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Extract data from an HTML table

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-HTML-Parser>=3.36:www/p5-HTML-Parser
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
