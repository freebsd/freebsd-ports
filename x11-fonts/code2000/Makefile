# New ports collection makefile for:	Code2000
# Date created:		6 Dec 2003
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	code2000
PORTVERSION=	1.13
CATEGORIES=	x11-fonts
MASTER_SITES=	http://home.att.net/~jameskass/
DISTFILES=	${PORTNAME:U}${EXTRACT_SUFX:U}
DIST_SUBDIR=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	thierry@pompo.net
COMMENT=	Shareware demo Unicode TrueType font

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir

NO_PACKAGE=	Only unmodified original package can be distributed

USE_X_PREFIX=	yes
USE_ZIP=	yes

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
RUN_DEPENDS=	xfstt:${PORTSDIR}/x11-servers/Xfstt
.endif

PLIST_SUB=	PKG_OLDXF86=${PKG_OLDXF86} \
		PKG_NSALIAS=${PKG_NSALIAS} \
		FONTNAME="${FONTNAME}" \
		FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		TTFONTSDIR="${TTFONTSDIR:S|${X11BASE}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
OLDXF86=	""
.else
OLDXF86=	"@comment "
.endif

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTFONTSDIR?=	${X11BASE}/lib/X11/fonts/TrueType

TTMKFDIR_CMD?=	${X11BASE}/bin/ttmkfdir
SORT?=		sort

#
# Post-extract
#

post-extract: move-fonts rename-license

move-fonts:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/CODE2000.TTF ${WRKSRC}/${FONTNAME}.ttf

rename-license:
	${MV} ${WRKDIR}/CODE2000.HTM ${WRKSRC}/${FONTNAME}.html

#
# Post-patch
#

post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#
# Build
#

do-build: make-fonts.scale make-fonts.dir

make-fonts.scale:
	${TTMKFDIR_CMD} -c -f JJK -d ${WRKSRC} | ${CAT} -n | ${SED} -e ' \
		s,^     1,100000,; \
		s,JJK,${FONTNAME},; \
	' | ${SORT} -r | ${CUT} -c 8- > ${WRKSRC}/fonts.scale

make-fonts.dir:
	${CP} ${WRKSRC}/fonts.scale ${WRKSRC}/fonts.dir

#
# Install
#

do-install: install-fonts

install-fonts:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/* ${FONTSDIR}

#
# Post-install
#

post-install: truetype-link display-message

truetype-link:
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
	${LN} -fs ${FONTSDIR} ${TTFONTSDIR}/${FONTNAME}
.endif

display-message:
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.post.mk>
