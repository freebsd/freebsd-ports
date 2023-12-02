PORTNAME=	fontmatrix
PORTVERSION=	0.9.100
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	x11-fonts

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Graphical font manager
WWW=		https://github.com/fcoiffie/fontmatrix

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Depends on deprecated www/qt5-webkit
EXPIRATION_DATE=	2023-12-31

LIB_DEPENDS=	libfontconfig.so:x11-fonts/fontconfig \
		libfreetype.so:print/freetype2

USES=		cmake compiler:c++11-lang qt:5

USE_GITHUB=	yes
USE_QT=		buildtools core gui linguisttools network printsupport \
		qmake:build sql svg webkit widgets xml

.include <bsd.port.mk>
