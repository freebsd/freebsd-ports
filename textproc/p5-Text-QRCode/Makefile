# New ports collection makefile for:	p5-Text-QRCode
# Date created:				2011/02/14
# Whom:					chinsan
#
# $FreeBSD$
#

PORTNAME=	Text-QRCode
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Generate text based QR Code

BUILD_DEPENDS=	libqrencode>=2.0.0:${PORTSDIR}/graphics/libqrencode
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes
CFLAGS+=	-I${LOCALBASE}/include

MAN3=		Text::QRCode.3

.include <bsd.port.mk>
