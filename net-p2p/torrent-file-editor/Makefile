PORTNAME=	torrent-file-editor
PORTVERSION=	0.3.18
CATEGORIES=	net-p2p
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/v${PORTVERSION}/

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	GUI tool for creating and editing .torrent files
WWW=		https://torrent-file-editor.github.io/

LICENSE=	GPLv3+

USES=		cmake compiler:c++11-lang desktop-file-utils qt:5
USE_QT=		buildtools:build linguisttools:build qmake:build \
		core gui widgets

CMAKE_ARGS=	-DQT5_BUILD:BOOL=ON \
		-DENABLE_PCH:BOOL=OFF

OPTIONS_DEFINE=	DONATION
OPTIONS_DEFAULT=	DONATION

DONATION_DESC=	Show donation text in the About dialog
DONATION_CMAKE_OFF=	-DDISABLE_DONATION:BOOL=ON

.include <bsd.port.mk>
