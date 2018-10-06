# Created by: ijliao
# $FreeBSD$

PORTNAME=	PDF-API2
PORTVERSION=	2.033
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Facilitates the creation and modification of PDF files

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Font-TTF>=0:x11-fonts/p5-Font-TTF
TEST_DEPENDS=	p5-Test-Exception>=0:devel/p5-Test-Exception \
		p5-Test-Memory-Cycle>=0:devel/p5-Test-Memory-Cycle

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
