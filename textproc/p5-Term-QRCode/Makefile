# New ports collection makefile for:	p5-Term-QRCode
# Date created:				2012/03/22
# Whom:					Stephon Chen <stephon@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Term-QRCode
PORTVERSION=	0.01
CATEGORIES=	textproc perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	stephon@gmail.com
COMMENT=	Generate QR Code on Terminal

BUILD_DEPENDS=	libqrencode>=2.0.0:${PORTSDIR}/graphics/libqrencode \
		p5-Text-QRCode>0:${PORTSDIR}/textproc/p5-Text-QRCode
RUN_DEPENDS:=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Term::QRCode.3

.include <bsd.port.mk>
