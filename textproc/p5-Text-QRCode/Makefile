# Created by: chinsan
# $FreeBSD$

PORTNAME=	Text-QRCode
PORTVERSION=	0.05
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate text based QR Code

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

LIB_DEPENDS=	libqrencode.so:graphics/libqrencode

USES=		perl5 pkgconfig
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's|qrencode.h|${LOCALBASE}/include/&|' ${WRKSRC}/Makefile.PL ${WRKSRC}/QRCode.xs

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Text/QRCode/QRCode.so

.include <bsd.port.mk>
