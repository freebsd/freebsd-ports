PORTNAME=	WinFF
PORTVERSION=	1.6.4
PORTREVISION=	7
CATEGORIES=	multimedia
MASTER_SITES=	https://github.com/WinFF/winff/archive/refs/tags/
PKGNAMESUFFIX=	${LAZARUS_PKGNAMESUFFIX}
DISTNAME=	${_PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Convert your videos quickly, easily, and all at once
WWW=		https://www.biggmatt.com/p/winff.html

LICENSE=	GPLv3

LIB_DEPENDS=	libavutil.so:multimedia/ffmpeg

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		fpc lazarus:flavors xorg
USE_XORG=	x11

#USE_GITHUB=	yes
#GH_PROJECT=	${_PORTNAME}

_PORTNAME=	${PORTNAME:tl}
DATADIR=	${PREFIX}/share/${_PORTNAME}
DOCSDIR=	${PREFIX}/share/doc/${_PORTNAME}

DESKTOP_ENTRIES=	"${PORTNAME}"	\
			"${COMMENT}"	\
			"${_PORTNAME}"	\
			"${_PORTNAME}"	\
			"AudioVideo;"	\
			true

LAZARUS_PROJECT_FILES=	winff.lpr
LAZBUILD_ARGS=		-d --pcp=${WRKSRC} --scp=${WRKDIR}

gtk2_CONFLICTS_INSTALL=	${PORTNAME}-qt5 ${PORTNAME}-qt6
qt5_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt6
qt6_CONFLICTS_INSTALL=	${PORTNAME}-gtk2 ${PORTNAME}-qt5

WRKSRC=		${WRKDIR}/${_PORTNAME}-${_PORTNAME}-${PORTVERSION}
BUILD_WRKSRC=	${WRKSRC}/${_PORTNAME}

.if ${FLAVOR:Ugtk2:Mgtk2}
USES+=		gnome
USE_GNOME+=	cairo
.endif

OPTIONS_DEFINE=	DOCS

pre-configure:
	${REINPLACE_CMD} -e 's|/usr/share|${PREFIX}/share|g' ${BUILD_WRKSRC}/unit1.pas
.for fp in unit1.pas unit4.pas scripts/check_presets.sh
	${REINPLACE_CMD} -e 's|/usr/bin/|${LOCALBASE}/bin/|g' ${BUILD_WRKSRC}/${fp}
.endfor

pre-build:
	${CP} -p ${LOCALBASE}/etc/fppkg.cfg ${WRKDIR}

do-install:
	${INSTALL_PROGRAM} ${BUILD_WRKSRC}/${PORTNAME:tl} ${STAGEDIR}${PREFIX}/bin
	${MKDIR} ${STAGEDIR}${DATADIR}/languages
	${INSTALL_DATA} ${BUILD_WRKSRC}/presets.xml ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/languages/* ${STAGEDIR}${DATADIR}/languages/
	${INSTALL_MAN} ${BUILD_WRKSRC}/${_PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1
	${INSTALL_DATA} ${BUILD_WRKSRC}/winff-icons/48x48/${_PORTNAME}.png \
		${STAGEDIR}${PREFIX}/share/pixmaps
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${BUILD_WRKSRC}/docs/*.pdf ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
