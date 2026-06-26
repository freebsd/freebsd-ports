PORTNAME=	Business-ISBN
PORTVERSION=	3.014
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BRIANDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers
WWW=		https://metacpan.org/release/Business-ISBN

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Business-ISBN-Data>=20191107:misc/p5-Business-ISBN-Data
TEST_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

PORTSCOUT=	limit:^[0-9\.]*$$

OPTIONS_DEFINE=	BARCODE XISBN
BARCODE_DESC=	Barcode support
XISBN_DESC=	xISBN support

BARCODE_BUILD_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
BARCODE_RUN_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
XISBN_BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww
XISBN_RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

.include <bsd.port.mk>
