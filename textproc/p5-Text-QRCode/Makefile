# Created by: chinsan
# $FreeBSD$

PORTNAME=	Text-QRCode
PORTVERSION=	0.01
PORTREVISION=	1
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	perl@FreeBSD.org
COMMENT=	Generate text based QR Code

BUILD_DEPENDS=	libqrencode>=2.0.0:${PORTSDIR}/graphics/libqrencode
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		Text::QRCode.3

.include <bsd.port.mk>
