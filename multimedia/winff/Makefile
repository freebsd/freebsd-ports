# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	WinFF
PORTVERSION=	1.5.5
PORTREVISION=	15
CATEGORIES=	multimedia
MASTER_SITES=	http://winff.org/docs/source/
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
DISTNAME=	${_PORTNAME}-${PORTVERSION}-source

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert your videos quickly, easily, and all at once

BROKEN=		unfetchable

LICENSE=	GPLv3

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

USES=		fpc lazarus:flavors xorg
USE_XORG=	x11
USE_FPC=	chm fcl-base fcl-image fcl-json fcl-xml pasjpeg regexpr x11

NO_WRKSUBDIR=	yes
_PORTNAME=	${PORTNAME:tl}
DATADIR=	${PREFIX}/share/${_PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${_PORTNAME}

DESKTOP_ENTRIES=	"${PORTNAME}"	\
			"${COMMENT}"	\
			"${_PORTNAME}"	\
			"${_PORTNAME}"	\
			"AudioVideo;"	\
			true

LAZARUS_NO_FLAVORS=	qt5
LAZARUS_PROJECT_FILES=	winff.lpr
LAZBUILD_ARGS=		-d

BUILD_WRKSRC=	${WRKDIR}/${PKGNAME}/${_PORTNAME}

.if ${FLAVOR:Ugtk2:Mgtk2}
USES+=		gnome
USE_FPC+=	cairo
USE_GNOME+=	cairo
INSTALLS_ICONS=yes
.endif

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${BUILD_WRKSRC}/unit1.pas
.for fp in unit1.pas unit4.pas scripts/check_presets.sh
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|g' ${BUILD_WRKSRC}/${fp}
.endfor

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/languages
	${INSTALL_DATA} ${BUILD_WRKSRC}/presets.xml ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/languages/* ${STAGEDIR}${DATADIR}/languages/
	${INSTALL_MAN} ${BUILD_WRKSRC}/${_PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1
	${INSTALL_DATA} ${BUILD_WRKSRC}/winff-icons/48x48/${_PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
