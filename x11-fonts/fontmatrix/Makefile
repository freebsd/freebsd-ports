# $FreeBSD$

PORTNAME=	fontmatrix
PORTVERSION=	0.9.100
DISTVERSIONPREFIX=	v
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical font manager

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang qt:5

USE_GITHUB=	yes
USE_QT=		buildtools core gui linguisttools network printsupport \
		qmake_build sql svg webkit widgets xml

.include <bsd.port.mk>
