# New ports collection makefile for:	texcm-ttf
# Date created:		6 March 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	texcm-ttf
PORTVERSION=	20010117
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.mozilla.org/projects/mathml/fonts/bakoma/
DISTFILES=	${PORTNAME}${EXTRACT_SUFX} license.txt
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}
EXTRACT_ONLY=	${PORTNAME}${EXTRACT_SUFX}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	TeX's Computer Modern Fonts

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

NO_CDROM=	"cannot be sold or distributed with any commercial product"

USE_X_PREFIX=	yes
USE_ZIP=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}

SUB_FILES=	pkg-message
SUB_LIST=	FONTSDIR="${FONTSDIR}"
PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

PKGMESSAGE=	${WRKDIR}/pkg-message

FONTNAME=	${PORTNAME}
FONTSDIR=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTMKFDIR_CMD=	${X11BASE}/bin/ttmkfdir

do-build:
	${TTMKFDIR_CMD} -c -f ${FONTNAME} -d ${WRKSRC} | ${CAT} -n |	\
		${SED} -e 's|^     1|100000|' | ${SORT} -r |		\
		${CUT} -c 8- > ${WRKSRC}/fonts.scale
	${CP} ${WRKSRC}/fonts.scale ${WRKSRC}/fonts.dir

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${FONTSDIR}
	${INSTALL_DATA} ${_DISTDIR}/license.txt ${FONTSDIR} # Required by the license

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
