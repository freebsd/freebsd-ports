# Created by: Jean-Yves Lefort <jylefort@FreeBSD.org>
# $FreeBSD$

PORTNAME=	icon-bluecurve-theme

COMMENT=	The Bluecurve icon set

BUILD_DEPENDS=	icon-slicer:${PORTSDIR}/graphics/icon-slicer \
		pamrgbatopng:${PORTSDIR}/graphics/netpbm

MASTERDIR=	${.CURDIR}/../bluecurve-themes

WANT_GNOME=	yes
INSTALLS_ICONS=	yes

BUILD_WRKSRC=	${WRKSRC}/art/icon/Bluecurve/sheets
BC_HIERS=	${BUILD_WRKSRC}/Bluecurve:${PREFIX}/share/icons/Bluecurve

NO_STAGE=	yes
do-build:
	@BUILD_WRKSRC="${BUILD_WRKSRC}" ${SH} ${SCRIPTDIR}/do-build

pre-install:
	@${ECHO_CMD} "@dirrm share/icons/Bluecurve" >> ${PLIST}
	@${ECHO_CMD} "@dirrmtry share/icons" >> ${PLIST}

.include "${MASTERDIR}/Makefile"
