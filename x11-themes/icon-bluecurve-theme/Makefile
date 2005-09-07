# New ports collection makefile for:	icon-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon-bluecurve-theme

COMMENT=	The Bluecurve icon set

BUILD_DEPENDS=	icon-slicer:${PORTSDIR}/graphics/icon-slicer

MASTERDIR=	${.CURDIR}/../bluecurve-themes

BUILD_WRKSRC=	${WRKSRC}/art/icon/Bluecurve/sheets
BC_HIERS=	${BUILD_WRKSRC}/Bluecurve:${PREFIX}/share/icons/Bluecurve

post-extract:
	@cd ${WRKDIR} && \
	${TAR} -zxf WeatherIcons.tar.gz && ${TAR} -zxf volume.tar.gz

do-build:
	${MKDIR} ${BUILD_WRKSRC}/Bluecurve
.for t in added apps dialogs emblems files stock ooo
	${LOCALBASE}/bin/icon-slicer \
		--output-dir=${BUILD_WRKSRC}/Bluecurve \
		--image-dir=${BUILD_WRKSRC} \
		${BUILD_WRKSRC}/icons-${t}.icontheme
.endfor
	${MKDIR} ${BUILD_WRKSRC}/Bluecurve/36x36/apps
	${MV} -f ${BUILD_WRKSRC}/gnome-spinner*.png ${BUILD_WRKSRC}/Bluecurve/36x36/apps
	${MV} -f ${WRKSRC}/art/icon/Bluecurve/index.theme ${BUILD_WRKSRC}/Bluecurve
.for d in 16x16 20x20 24x24 32x32 48x48
	${MV} -f ${WRKDIR}/WeatherIcons/${d}/* ${BUILD_WRKSRC}/Bluecurve/${d}/stock
	${MV} -f ${WRKDIR}/volume/${d}/* ${BUILD_WRKSRC}/Bluecurve/${d}/stock
.endfor
	cd ${BUILD_WRKSRC}/Bluecurve/48x48/apps && \
	${LN} -sf gnome-main-menu.png gnome-logo-icon-transparent.png
.for d in 16x16 24x24 32x32 48x48
	cd ${BUILD_WRKSRC}/Bluecurve/${d}/apps && \
	${LN} -sf icon-db-user.png openofficeorg-base.png && \
	${LN} -sf redhat-spreadsheet.png openofficeorg-calc.png && \
	${LN} -sf icon-vector-editor.png openofficeorg-draw.png && \
	${LN} -sf redhat-presentations.png openofficeorg-impress.png && \
	${LN} -sf icon-calculator.png openofficeorg-math.png && \
	${LN} -sf redhat-word-processor.png openofficeorg-writer.png
.endfor
	cd ${BUILD_WRKSRC}/Bluecurve/48x48/filesystems && \
	${LN} -sf ../mimetypes/fileshare.png gnome-fs-ftp.png

pre-install:
	@${ECHO_CMD} "@dirrm share/icons/Bluecurve" >> ${PLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/icons 2>/dev/null || true" >> ${PLIST}

.include "${MASTERDIR}/Makefile"
