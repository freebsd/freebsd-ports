# New ports collection makefile for:	icon-bluecurve-theme
# Date created:			29 May 2005
# Whom:				Jean-Yves Lefort <jylefort@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	icon-bluecurve-theme

COMMENT=	The Bluecurve icon set

BUILD_DEPENDS=	icon-slicer:${PORTSDIR}/graphics/icon-slicer \
		pamrgbatopng:${PORTSDIR}/graphics/netpbm-devel

MASTERDIR=	${.CURDIR}/../bluecurve-themes

EXTRA_PATCHES=	${WRKDIR}/redhat-artwork-5.0.5-add-dirs-to-bluecurve-theme-index.patch
PATCH_STRIP=	-p1

WANT_GNOME=	yes
INSTALLS_ICONS=	yes

BUILD_WRKSRC=	${WRKSRC}/art/icon/Bluecurve/sheets
BC_HIERS=	${BUILD_WRKSRC}/Bluecurve:${PREFIX}/share/icons/Bluecurve

do-build:
	@BUILD_WRKSRC="${BUILD_WRKSRC}" ${SH} ${SCRIPTDIR}/do-build

pre-install:
	@${ECHO_CMD} "@dirrm share/icons/Bluecurve" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/icons" >> ${PLIST}

.include "${MASTERDIR}/Makefile"
