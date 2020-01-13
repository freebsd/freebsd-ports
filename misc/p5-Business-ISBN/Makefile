# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Business-ISBN
PORTVERSION=	3.005
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN/Business CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	${RUN_DEPENDS}
RUN_DEPENDS=	p5-Business-ISBN-Data>=20191107:misc/p5-Business-ISBN-Data
TEST_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode

USES=		perl5
USE_PERL5=	configure

NO_ARCH=	yes

OPTIONS_DEFINE=	BARCODE XISBN
BARCODE_DESC=	Barcode support
XISBN_DESC=	xISBN support

BARCODE_BUILD_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
BARCODE_RUN_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
XISBN_BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww
XISBN_RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

.include <bsd.port.mk>
