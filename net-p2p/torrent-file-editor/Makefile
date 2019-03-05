# Created by: Alexey Dokuchaev <danfe@FreeBSD.org>
# $FreeBSD$

PORTNAME=	torrent-file-editor
PORTVERSION=	0.3.13
PORTREVISION=	3
CATEGORIES=	net-p2p
MASTER_SITES=	SF/${PORTNAME}/v${PORTVERSION}

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Qt-based GUI tool for creating and editing .torrent files

LICENSE=	GPLv3

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5
USE_QT=		buildtools_build linguisttools_build qmake_build \
		core gui widgets

CMAKE_ARGS=	-DQT5_BUILD:BOOL=ON

OPTIONS_DEFINE=	DONATION
OPTIONS_DEFAULT=	DONATION

DONATION_DESC=	Show donation text in the About dialog
DONATION_CMAKE_OFF=	-DDISABLE_DONATION:BOOL=ON

post-patch:
# Avoid conflict with C++20 <version> by adding .txt suffix
	@${REINPLACE_CMD} -i .c++20 '/file/s/version/&.txt/' \
		${WRKSRC}/Version.cmake ${WRKSRC}/Dmg.cmake

.include <bsd.port.mk>
