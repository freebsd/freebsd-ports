# New ports collection makefile for:	mathfonts
# Date created:		6 March 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	mathfonts
PORTVERSION=	4.1	# Don't upgrade this port if not supported by MathML-enabled Mozilla
# 			# Please check http://www.mozilla.org/projects/mathml/fonts/
PORTREVISION=	5
CATEGORIES=	x11-fonts
MASTER_SITES=	http://support.wolfram.com/mathematica/systems/windows/general/files/
DISTNAME=	MathFonts_TrueType_${PORTVERSION:S/.//}
EXTRACT_SUFX=	.exe
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Mathematica fonts for MathML-enabled Mozilla

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir
RUN_DEPENDS=	${FONTSBASE}/texcm-ttf/cmr10.ttf:${PORTSDIR}/x11-fonts/texcm-ttf

RESTRICTED=	no distribution of the fonts allowed
NO_CDROM=	${RESTRICTED}

USE_ZIP=	yes
NO_WRKSUBDIR=	yes

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR="${FONTSDIR}"
PLIST_SUB+=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

PKGMESSAGE=	${WRKDIR}/pkg-message

FONTNAME=	${PORTNAME}
FONTSBASE=	${X11BASE}/lib/X11/fonts
FONTSDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${X11BASE}/bin/mkfontscale
MKFONTDIR_CMD=	${X11BASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC} &&	${MKFONTSCL_CMD}
	cd ${WRKSRC} &&	${MKFONTDIR_CMD}
.for f in fonts.dir fonts.scale
	${REINPLACE_CMD} -e 's|-misc-math|-mathfonts-Math|;	\
		s|-misc-????-|-altsys-ahMn-|' ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${WRKSRC}/fonts.scale ${WRKSRC}/fonts.dir	\
		${FONTSDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
