# New ports collection makefile for:	TrueType core fonts for the Web
# Date created:		12 Jan 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	webfonts
PORTVERSION=	0.21
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.microsoft.com/typography/downloads/ \
		http://www.eu.microsoft.com/typography/downloads/ \
		http://www.asia.microsoft.com/typography/downloads/
.if defined(WITH_ARIAL_UNICODE)
MASTER_SITES+=	http://download.microsoft.com/download/publisher2000/Aruniup/2000/WIN98/EN-US/
.endif
DISTFILES=	andale32.exe trebuc32.exe georgi32.exe verdan32.exe \
		comic32.exe arialb32.exe impact32.exe arial32.exe \
		times32.exe courie32.exe webdin32.exe
.if defined(WITH_ARIAL_UNICODE)
DISTFILES+=	Aruniupd.exe
.endif
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kkonstan@daemon.gr

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir \
		cabextract:${PORTSDIR}/archivers/cabextract
.if ${XFREE86_VERSION} == 3
RUN_DEPENDS=	xfstt:${PORTSDIR}/x11-servers/Xfstt
.endif

RESTRICTED=	"Restrictive license - cannot place on server for distribution"
NO_CDROM=	"Restrictive license - cannot sell for profit"
NO_PACKAGE=	"Restrictive license - cannot distribute in modified form"

EXTRACT_CMD=		${LOCALBASE}/bin/cabextract
EXTRACT_BEFORE_ARGS=	--lowercase --quiet
EXTRACT_AFTER_ARGS=

USE_X_PREFIX=	yes
PLIST_SUB=	PKG_OLDXF86=${PKG_OLDXF86} \
		PKG_NSALIAS=${PKG_NSALIAS} \
		PKG_UNICODE=${PKG_UNICODE} \
		FONTNAME="${FONTNAME}" \
		FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		TTFONTSDIR="${TTFONTSDIR:S|${X11BASE}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.if ${XFREE86_VERSION} == 3
OLDXF86=
.else
OLDXF86=        "@comment "
.endif

.if defined(WITH_NETSCAPE_ALIASES)
PKG_NSALIAS=
.else
PKG_NSALIAS=    "@comment "
.endif

.if defined(WITH_ARIAL_UNICODE)
PKG_UNICODE=
.else
PKG_UNICODE=    "@comment "
.endif

#
# Local variables
#

FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTFONTSDIR?=	${X11BASE}/lib/X11/fonts/TrueType

TTMKFDIR_CMD?=	${X11BASE}/bin/ttmkfdir
SORT?=	sort

# The following are for the NS aliases, feel free to tweak them!
FONTSIZES=      8 9 10 12 14 16 18 20 24
FONTLIMIT=      11

.SILENT:

#
# Display options
#

pre-everything::
.if !defined(WITH_NETSCAPE_ALIASES)
	${ECHO_MSG}
	${ECHO_MSG} "If you want font aliases that work around Netscape's tiny font bug (4.x ONLY),"
	${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_NETSCAPE_ALIASES=yes\""
	${ECHO_MSG}
.endif
.if !defined(WITH_ARIAL_UNICODE)
	${ECHO_MSG}
	${ECHO_MSG} "If you want \"Arial Unicode MS\", a complete Unicode 2.1 font (13.7MB download),"
	${ECHO_MSG} "hit Ctrl-C right now and use \"make WITH_ARIAL_UNICODE=yes\""
	${ECHO_MSG}
.endif

#
# Post-extract
#

post-extract: move-fonts rename-license remove-extras

move-fonts:
	${MKDIR} ${WRKSRC}
	${MV} ${WRKDIR}/*.ttf ${WRKSRC}

rename-license:
	${MV} ${WRKDIR}/licen.txt ${WRKSRC}/LICENSE

remove-extras:
	${RM} -f ${WRKDIR}/*.dll ${WRKDIR}/*.exe ${WRKDIR}/*.inf

#
# Post-patch
#

post-patch: patch-message

patch-message:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#
# Build
#

do-build: make-fonts.scale make-fonts.dir make-fonts.alias

make-fonts.scale:
	${TTMKFDIR_CMD} -c -d ${WRKSRC} | ${CAT} -n | ${SED} -e ' \
		s,^     1,100000,; \
		s,monotype,${FONTNAME},; \
		s,microsoft,${FONTNAME},; \
	' | ${SORT} -r | ${CUT} -c 8- > ${WRKSRC}/fonts.scale

make-fonts.dir:
	${CP} ${WRKSRC}/fonts.scale ${WRKSRC}/fonts.dir

make-fonts.alias:
.if defined(WITH_NETSCAPE_ALIASES)
	${ECHO_MSG}
	${ECHO_MSG} -n "Building aliases for Netscape..."
	[ -t 0 ] && tty=/dev/tty || tty=/dev/null; \
	${TAIL} +2 ${WRKSRC}/fonts.scale | ${CUT} -f 2- -d" " | \
	while read font; do \
		${ECHO} \"$${font}\" \"$${font}\"; \
		for nsize in ${FONTSIZES}; do \
			tsize=$${nsize}; \
			[ $${tsize} -lt ${FONTLIMIT} ] && tsize=${FONTLIMIT}; \
			${ECHO} \"$${font}\" \"$${font}\" | \
			${SED}	-e "s,--0-0-0-0-,--$${nsize}-$${nsize}0-0-0-," \
			      -e "s,--0-0-0-0-,--$${tsize}-$${tsize}0-75-75-," \
			      -e "s,^\"-${FONTNAME},\"-netscape,"; \
		done; \
		${ECHO_MSG} -n "." > $${tty}; \
	done | \
	${SED} -n -e p -e "\
		s,-Arial-,-Helvetica-,p; \
		s,-Helvetica-,-MS Sans Serif-,p; \
		s,-Times New Roman-,-Times-,p; \
		s,-Courier New-,-Courier-,p; \
	" | \
	${SED} -e '/"\([^"]*\)" "\1"/d' > ${WRKSRC}/fonts.alias
	${ECHO_MSG}
.endif

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
.if ${XFREE86_VERSION} == 3
	${LN} -fs ${FONTSDIR} ${TTFONTSDIR}/${FONTNAME}
.endif

display-message:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.mk>
