# New ports collection makefile for: jahshaka
# Date created:		07 Feb 2005
# Whom:			Igor Pokrovsky <ip@doom.homeunix.org>
#
# $FreeBSD$
#

PORTNAME=	jahshaka
PORTVERSION=	1.9a9
PORTREVISION=	6
CATEGORIES=	multimedia
MASTER_SITES=	SF/${PORTNAME}fx/Jahshaka-source/1.9alpha
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Video and film composing, editing and special fx system

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	aviplay.0:${PORTSDIR}/multimedia/avifile \
		freetype.9:${PORTSDIR}/print/freetype2 \
		jpeg.10:${PORTSDIR}/graphics/jpeg

USE_GL=		glut
USE_QT_VER=	3
MAKE_ENV=	QMAKESPEC=${QMAKESPEC} QTDIR=${QT_PREFIX}
WRKSRC=		${WRKDIR}/${PORTNAME}

PORTDOCS=	README

TCSH?=		/bin/csh
QMAKE?=		${LOCALBASE}/bin/qmake
QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 700042
BROKEN=		does not compile with GCC 4.2
.endif

post-patch:
	@(${FIND} ${WRKSRC} -name '*.h' -or -name '*.cpp' | ${XARGS} ${REINPLACE_CMD} -i '' \
		-e 's|avifile-0.7|avifile|g; s|malloc\.h|stdlib\.h|g')
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|g" \
		${WRKSRC}/jahshakaSettings.pro
	@${REINPLACE_CMD} -e "s|qmake|${QMAKE}|g" \
		${WRKSRC}/configure ${WRKSRC}/plugins/configure
	@${REINPLACE_CMD} -i '' -e "s|%%DATADIR%%|${DATADIR}|g" \
		${WRKSRC}/jah/Source/jahshaka.cpp
	@${REINPLACE_CMD} -i '' \
	-e "s|JahBasePath+\"plugins/\"|\"${PREFIX}/lib/${PORTNAME}/plugins/\"|g" \
		${WRKSRC}/jah/libraries/jahplugins/jahpluginlib.cpp

do-configure:
	cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${TCSH} ./configure
	cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} ${TCSH} ./configure

post-build:
	cd ${WRKSRC}/plugins && ${SETENV} ${MAKE_ENV} ${MAKE}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

# UI pics
	${MKDIR} ${DATADIR}
.for ext in bmp jpg gif png xpm
.for dir in "" desktop desktopController interface jahplayer modules paint player
	${MKDIR} ${DATADIR}/Pixmaps/${dir}
	${FIND} -X ${WRKSRC}/Pixmaps/${dir} -name "*.${ext}" -depth 1 | \
		${XARGS} -J % ${INSTALL_DATA} % ${DATADIR}/Pixmaps/${dir}
.endfor
.endfor

# database
	${MKDIR} ${DATADIR}/database
	${INSTALL_DATA} ${WRKSRC}/database/* ${DATADIR}/database

# fonts
	${MKDIR} ${DATADIR}/fonts
	${INSTALL_DATA} ${WRKSRC}/fonts/*.ttf ${DATADIR}/fonts

# scenes
	${MKDIR} ${DATADIR}/scenes
	${INSTALL_DATA} ${WRKSRC}/scenes/*.jsf ${DATADIR}/scenes

# media for scenes
	${MKDIR} ${DATADIR}/media
	${MKDIR} ${DATADIR}/media/images
	${INSTALL_DATA} ${WRKSRC}/media/images/* ${DATADIR}/media/images
	${MKDIR} ${DATADIR}/media/models
	${INSTALL_DATA} ${WRKSRC}/media/models/* ${DATADIR}/media/models

# plugins
	${MKDIR} ${PREFIX}/lib/${PORTNAME}
	${MKDIR} ${PREFIX}/lib/${PORTNAME}/plugins ${DATADIR}/plugins
	${FIND} -X ${WRKSRC}/plugins -name '*.so' | \
	${XARGS} -J % ${INSTALL_PROGRAM} % ${PREFIX}/lib/${PORTNAME}/plugins
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} \* ${DATADIR}/plugins "-name *\.fp")

.ifndef (NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
