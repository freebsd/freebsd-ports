# Created by: Stephon Chen <stephon@gmail.com>
# $FreeBSD$

PORTNAME=	Term-QRCode
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	stephon@gmail.com
COMMENT=	Generate QR Code on Terminal

LICENSE=	ART10 GPLv1
LICENSE_COMB=	dual

BUILD_DEPENDS=	libqrencode>=2.0.0:${PORTSDIR}/graphics/libqrencode \
		p5-Text-QRCode>0:${PORTSDIR}/textproc/p5-Text-QRCode
RUN_DEPENDS:=	${BUILD_DEPENDS}

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.mk>
