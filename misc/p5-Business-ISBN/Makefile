# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Business-ISBN
PORTVERSION=	3.004
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN/Business CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers

LICENSE=	ART20
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	p5-Business-ISBN-Data>=20140910.002:misc/p5-Business-ISBN-Data
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode

OPTIONS_DEFINE=	BARCODE XISBN
BARCODE_DESC=	Barcode support
XISBN_DESC=	xISBN support

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

BARCODE_BUILD_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
BARCODE_RUN_DEPENDS=	p5-GD-Barcode>=0:graphics/p5-GD-Barcode
XISBN_BUILD_DEPENDS=	p5-libwww>=0:www/p5-libwww
XISBN_RUN_DEPENDS=	p5-libwww>=0:www/p5-libwww

.include <bsd.port.mk>
