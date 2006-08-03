# New ports collection makefile for:	Code2000
# Date created:		6 Dec 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	code2000
PORTVERSION=	1.16
CATEGORIES=	x11-fonts
MASTER_SITES=	http://home.att.net/~jameskass/
DISTFILES=	${PORTNAME:U}${EXTRACT_SUFX:U}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Shareware demo Unicode TrueType font

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

NO_PACKAGE=	Only unmodified original package can be distributed

USE_X_PREFIX=	yes
USE_ZIP=	yes

PLIST_SUB=	FONTSDIR="${FONTSDIR:S|${PREFIX}/||}"

SUB_FILES=	pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message
SUB_LIST=	FONTSDIR=${FONTSDIR}

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTFONTSDIR?=	${X11BASE}/lib/X11/fonts/TrueType

TTMKFDIR_CMD?=	${X11BASE}/bin/ttmkfdir

post-extract: move-fonts rename-license

move-fonts:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/CODE2000.TTF ${WRKSRC}/${FONTNAME}.ttf

rename-license:
	${MV} ${WRKDIR}/CODE2000.HTM ${WRKSRC}/${FONTNAME}.html

do-build: make-fonts.scale make-fonts.dir

make-fonts.scale:
	cd ${WRKSRC} && ${TTMKFDIR_CMD} -c -f JJK -d .
	${CAT} -n ${WRKSRC}/fonts.scale | ${SED} -e ' \
		s,^     1,100000,; \
		s,JJK,${FONTNAME},; \
	' | ${SORT} -r | ${CUT} -c 8- > ${WRKSRC}/fonts.scale.new
	${MV} ${WRKSRC}/fonts.scale.new ${WRKSRC}/fonts.scale

make-fonts.dir:
	${CP} ${WRKSRC}/fonts.scale ${WRKSRC}/fonts.dir

do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${FONTSDIR}

post-install:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
