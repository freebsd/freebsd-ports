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

do-build:
	${MKDIR} ${BUILD_WRKSRC}/Bluecurve
.for t in added apps dialogs emblems files stock ooo
	${LOCALBASE}/bin/icon-slicer \
		--output-dir=${BUILD_WRKSRC}/Bluecurve \
		--image-dir=${BUILD_WRKSRC} \
		${BUILD_WRKSRC}/icons-${t}.icontheme
.endfor
	${MKDIR} ${BUILD_WRKSRC}/Bluecurve/36x36/apps
	${CP} -f ${BUILD_WRKSRC}/gnome-spinner*.png ${BUILD_WRKSRC}/Bluecurve/36x36/apps
	${CP} -f ${WRKSRC}/art/icon/Bluecurve/index.theme ${BUILD_WRKSRC}/Bluecurve

pre-install:
	@${ECHO_CMD} "@dirrm share/icons/Bluecurve" >> ${PLIST}
	@${ECHO_CMD} "@unexec rmdir %D/share/icons 2>/dev/null || true" >> ${PLIST}

.include "${MASTERDIR}/Makefile"
