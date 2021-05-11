# created by: cmt@FreeBSD.org

PORTNAME=	PDF-Builder
PORTVERSION=	3.022
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	cmt@FreeBSD.org
COMMENT=	Facilitates the creation and modification of PDF files

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Font-TTF>=1.04:x11-fonts/p5-Font-TTF \
		p5-Image-PNG-Libpng>=0.56:graphics/p5-Image-PNG-Libpng
TEST_DEPENDS=	p5-Test-Exception>0:devel/p5-Test-Exception \
		p5-Test-Memory-Cycle>=1.0:devel/p5-Test-Memory-Cycle

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

.include <bsd.port.mk>
