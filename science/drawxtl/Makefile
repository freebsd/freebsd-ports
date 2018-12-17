# $FreeBSD$

PORTNAME=	DRAWxtl
DISTVERSION=	5.5
CATEGORIES=	science
MASTER_SITES=	https://www.lwfinger.com/drawxtl/
DISTNAME=	${PORTNAME}${DISTVERSION:S/.//}

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Crystal structure visualization tool

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfltk.so:x11-toolkits/fltk

USES=		desktop-file-utils gl gmake localbase
USE_GL=		gl glu
USE_XORG=	xinerama xft xext x11 xpm

BINARY_ALIAS=	gcc=${CC} g++=${CXX}

WRKSRC=		${WRKDIR}/${PORTNAME}/source/${DISTNAME}

PLIST_FILES=	bin/${PORTNAME} share/pixmaps/${PORTNAME}.xpm

DESKTOP_ENTRIES="${PORTNAME}" \
		"${COMMENT}" \
		"${PREFIX}/share/pixmaps/${PORTNAME}.xpm" \
		"${PORTNAME}" \
		"Chemistry;Physics;Science;Education;Viewer;" \
		""
POST_PLIST=	complete-desktop-entries

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/../../exe/${DISTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.xpm ${STAGEDIR}${PREFIX}/share/pixmaps

complete-desktop-entries:
	@${ECHO} "MimeType=chemical/x-cif;chemical/x-shelx;" >> ${STAGEDIR}${DESKTOPDIR}/${PORTNAME}.desktop

.include <bsd.port.mk>
