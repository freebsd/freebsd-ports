# New ports collection makefile for:	TrueType core fonts for the Web
# Date created:		12 Jan 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	webfonts
PORTVERSION=	0.12
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.microsoft.com/typography/downloads/
DISTFILES=	andale32.exe trebuc32.exe georgi32.exe verdan32.exe \
		comic32.exe arialb32.exe impact32.exe arial32.exe \
		times32.exe courie32.exe webdin32.exe
DIST_SUBDIR=	webfonts

MAINTAINER=	kkonstan@daemon.gr

BUILD_DEPENDS=	ttmkfdir:${PORTSDIR}/x11-fonts/ttmkfdir \
		cabextract:${PORTSDIR}/archivers/cabextract

RESTRICTED=	"Restrictive license \(can\'t place on server for distribution\)"
NO_CDROM=	"Restrictive license \(can\'t sell for profit\)"
NO_PACKAGE=	"Restrictive license \(can\'t distribute in forms other than the original\)"

USE_X_PREFIX=	yes

EXTRACT_CMD=	cabextract
EXTRACT_BEFORE_ARGS=
EXTRACT_AFTER_ARGS=	>/dev/null

post-extract:
	@${MKDIR} ${WRKDIR}/webfonts
	@${MV} ${WRKDIR}/*.* ${WRKDIR}/webfonts
	@${RM} ${WRKDIR}/webfonts/*.[Dd][Ll][Ll]
	@${RM} ${WRKDIR}/webfonts/*.[Ee][Xx][Ee]
	@${RM} ${WRKDIR}/webfonts/*.[Ii][Nn][Ff]
	@for file in `cd ${WRKDIR}/webfonts; ${ECHO} *` ; do \
		${MV}	`${ECHO} ${WRKDIR}/webfonts/$${file}` \
			`${ECHO} ${WRKDIR}/webfonts/``${ECHO} $${file} | ${AWK} 'BEGIN { FS=" " } { print tolower($$1) }'` ;\
	done
	@${MV} ${WRKDIR}/webfonts/licen.txt ${WRKDIR}/webfonts/LICENSE
	@${CHMOD} 644 ${WRKDIR}/webfonts/*

do-build:
	@ttmkfdir -d ${WRKDIR}/webfonts | \
		${SED} -e "s,monotype,truetype,g;s,microsoft,truetype,g" > ${WRKDIR}/webfonts/fonts.scale
	@head -1 ${WRKDIR}/webfonts/fonts.scale > ${WRKDIR}/webfonts/fonts.dir
	@tail +2 ${WRKDIR}/webfonts/fonts.scale | ${CAT} -n | sort -r | cut -c8- >>${WRKDIR}/webfonts/fonts.dir
	@cp ${WRKDIR}/webfonts/fonts.dir ${WRKDIR}/webfonts/fonts.scale
	@cp /dev/null ${WRKDIR}/webfonts/fonts.alias
.if !defined(WITHOUT_NETSCAPE)
	@${ECHO} ""
	@${ECHO} "Building aliases for Netscape. You can skip this by defining WITHOUT_NETSCAPE."
	@${ECHO} -n "This might take a few minutes, please be patient..."
	@tail +2 ${WRKDIR}/webfonts/fonts.scale | cut -f2- -d" " | while read LINE; do \
		for NSIZE in 8 9 10 12 14 16 18 20 24 ; do \
			if [ $${NSIZE} -lt 11 ] ; then \
				TSIZE=11 ;\
			else \
				TSIZE=$${NSIZE} ;\
			fi ;\
			TFONT=`${ECHO} $${LINE} | ${SED} -e "s,--0-0-0-0-,--$${TSIZE}-$${TSIZE}0-75-75-,g"` ;\
			NFONT=`${ECHO} $${LINE} | ${SED} -e "s,--0-0-0-0-,--$${NSIZE}-$${NSIZE}0-0-0-,g; s,truetype,netscape,g"` ;\
			${ECHO} "\"$${NFONT}\" \"$${TFONT}\"" >>${WRKDIR}/webfonts/fonts.alias ;\
		done ;\
		${ECHO} -n "." ;\
	done
	@cp ${WRKDIR}/webfonts/fonts.alias ${WRKDIR}/webfonts/fonts.tmp
	@grep -- "-netscape-Arial-" ${WRKDIR}/webfonts/fonts.tmp | \
		${SED} -e "s,-netscape-Arial-,-netscape-MS Sans Serif-,g" >>${WRKDIR}/webfonts/fonts.alias
	@grep -- "-netscape-Arial-" ${WRKDIR}/webfonts/fonts.tmp | \
		${SED} -e "s,-netscape-Arial-,-netscape-helvetica-,g" >>${WRKDIR}/webfonts/fonts.alias
	@grep -- "-netscape-Times New Roman-" ${WRKDIR}/webfonts/fonts.tmp | \
		${SED} -e "s,-netscape-Times New Roman-,-netscape-times-,g" >>${WRKDIR}/webfonts/fonts.alias
	@grep -- "-netscape-Courier New-" ${WRKDIR}/webfonts/fonts.tmp | \
		${SED} -e "s,-netscape-Courier New-,-netscape-courier-,g" >>${WRKDIR}/webfonts/fonts.alias
	@${RM} -f ${WRKDIR}/webfonts/fonts.tmp
	@${ECHO} ""
.endif
	@${CHMOD} 644 ${WRKDIR}/webfonts/*

do-install:
	@${MKDIR} ${PREFIX}/lib/X11/fonts/webfonts
	@${CP} ${WRKDIR}/webfonts/* ${PREFIX}/lib/X11/fonts/webfonts
	@${CHMOD} 755 ${PREFIX}/lib/X11/fonts/webfonts
	@${CHMOD} 644 ${PREFIX}/lib/X11/fonts/webfonts/*

post-install:
	@${ECHO} ""
	@${CAT} ${PKGMESSAGE}
	@${ECHO} ""

.include <bsd.port.mk>
