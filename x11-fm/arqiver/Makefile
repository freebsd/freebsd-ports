PORTNAME=	arqiver
DISTVERSION=	0.9.0
CATEGORIES=	x11-fm
MASTER_SITES=	https://github.com/tsujan/${PORTNAME}/releases/download/V${DISTVERSION}/
DISTNAME=	Arqiver-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Simple Qt archive manager
WWW=		https://github.com/tsujan/Arqiver

LICENSE=	GPLv3

USES=		cmake qt:5 tar:xz xorg
USE_XORG=	xcb
USE_QT=		buildtools:build qmake:build \
		core gui linguist svg widgets \
		x11extras

OPTIONS_DEFINE=	7ZIP ARJ LZO RAR ZIP
OPTIONS_DEFAULT=	7ZIP ARJ LZO RAR ZIP

7ZIP_DESC=	7zip archive support
7ZIP_RUN_DEPENDS=	7z:archivers/7-zip

ARJ_DESC=	ARJ archive support
ARJ_RUN_DEPENDS=	arj:archivers/arj

LZO_RUN_DEPENDS=	lzop:archivers/lzop

RAR_DESC=	RAR archive support
RAR_RUN_DEPENDS=	rar:archivers/rar \
			unrar:archivers/unrar

ZIP_DESC=	ZIP archive support
ZIP_RUN_DEPENDS=	zip:archivers/zip

.include <bsd.port.mk>
