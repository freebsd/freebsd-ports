# Created by: Thierry Thomas <thierry@pompo.net>
# $FreeBSD$

PORTNAME=	texcm-ttf
PORTVERSION=	20010117
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www-archive.mozilla.org/projects/mathml/fonts/bakoma/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} license.txt
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	TeX's Computer Modern Fonts

BUILD_DEPENDS=	mkfontscale:${PORTSDIR}/x11-fonts/mkfontscale	\
		mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

DEPRECATED=	Should be replaced by x11-fonts/stix-fonts
EXPIRATION_DATE=2014-05-03
NO_CDROM=	Cannot be sold or distributed with any commercial product

USES=		zip
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"
REINPLACE_ARGS=	-i ""

PKGMESSAGE=	${WRKDIR}/pkg-message

FONTNAME=	${PORTNAME}
FONTSDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}

MKFONTSCL_CMD=	${LOCALBASE}/bin/mkfontscale
MKFONTDIR_CMD=	${LOCALBASE}/bin/mkfontdir

do-build:
	cd ${WRKSRC} &&	${MKFONTSCL_CMD}
	cd ${WRKSRC} &&	${MKFONTDIR_CMD}
.for f in fonts.dir fonts.scale
	${REINPLACE_CMD} -e 's|-misc-|-texcm-|' ${WRKSRC}/${f}
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${STAGEDIR}${FONTSDIR}
	${INSTALL_DATA} ${_DISTDIR}/license.txt ${STAGEDIR}${FONTSDIR} # Required by the license

.include <bsd.port.mk>
