# Created by: Seamus Venasse <svenasse@polaris.ca>
# $FreeBSD$

PORTNAME=	Business-ISBN
PORTVERSION=	2.010
CATEGORIES=	misc perl5
MASTER_SITES=	CPAN
MASTER_SITE_SUBDIR=	CPAN:BDFOY
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Work with International Standard Book Numbers

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	p5-Business-ISBN-Data>=20140910.002:${PORTSDIR}/misc/p5-Business-ISBN-Data \
		p5-Mojolicious>=0:${PORTSDIR}/www/p5-Mojolicious
RUN_DEPENDS:=	${BUILD_DEPENDS}
TEST_DEPENDS=	p5-GD-Barcode>=0:${PORTSDIR}/graphics/p5-GD-Barcode

OPTIONS_DEFINE=	BARCODE XISBN
BARCODE_DESC=	Barcode support
XISBN_DESC=	xISBN support

NO_ARCH=	yes
USES=		perl5
USE_PERL5=	configure

BARCODE_BUILD_DEPENDS=	p5-GD-Barcode>=0:${PORTSDIR}/graphics/p5-GD-Barcode
BARCODE_RUN_DEPENDS=	p5-GD-Barcode>=0:${PORTSDIR}/graphics/p5-GD-Barcode
XISBN_BUILD_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww
XISBN_RUN_DEPENDS=	p5-libwww>=0:${PORTSDIR}/www/p5-libwww

.include <bsd.port.mk>
