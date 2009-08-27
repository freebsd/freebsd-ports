# New ports collection makefile for:	TrueType core fonts for the Web
# Date created:		12 Jan 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	webfonts
PORTVERSION=	0.30
PORTREVISION=	6
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_NETBSD:S/%SUBDIR%/ms-ttf/}:group1 \
		SF/corefonts/the%20fonts/final:group1 \
		ftp://ftp.uni-koeln.de/pc/win32/msoft/:group1 \
		ftp://ftp.vsu.ru/pub/tex/font-packs/mscore/:group1 \
		ftp://ftp.sinn.ru/pub/win95/fonts/:group1 \
		ftp://ftp.botik.ru/rented/znamensk/distributions/ftp.vsu.ru/pub/tex/font-packs/mscore/:group1 \
		http://download.microsoft.com/download/ie6sp1/finrel/6_sp1/W98NT42KMeXP/EN-US/:group2 \
		http://www.zeuscat.com/andrew/software/corefonts/:group2 \
		ftp://ftp.isu.edu.tw/pub/MsDownload/ie6sp1/en/:group2
DISTFILES=	andale32.exe:group1  arial32.exe:group1 arialb32.exe:group1 \
		comic32.exe:group1 courie32.exe:group1 georgi32.exe:group1 \
		impact32.exe:group1  times32.exe:group1 trebuc32.exe:group1 \
		verdan32.exe:group1 webdin32.exe:group1
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kkonstan@duth.gr
COMMENT=	TrueType core fonts for the Web

EXTRACT_DEPENDS=cabextract:${PORTSDIR}/archivers/cabextract
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig

NO_BUILD=	yes
RESTRICTED=	Restrictive license - cannot sell for profit or distribute in modified form

EXTRACT_CMD=		${LOCALBASE}/bin/cabextract
EXTRACT_BEFORE_ARGS=	-qLF '*.ttf' -d ${WRKSRC}
EXTRACT_AFTER_ARGS=

#
# Local variables
#
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTFONTSDIR?=	${LOCALBASE}/lib/X11/fonts/TrueType

PLIST_SUB=	FONTNAME="${FONTNAME}" \
		FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		TTFONTSDIR="${TTFONTSDIR:S|${LOCALBASE}/||}"

SUB_LIST=	FONTSDIR="${FONTSDIR}"
SUB_FILES=	pkg-message

FONTS_FILE=	${WRKDIR}/fonts.dir

.include <bsd.port.pre.mk>

.if defined(WITH_MSWINDOWS_LICENSE)
DISTFILES+=	ielpkth.cab:group2
.endif

.SILENT:

#
# Post-extract
#
post-extract:
	${EXTRACT_CMD} -qLF '*.txt' -d ${WRKSRC} ${_DISTDIR}/webdin32.exe

#
# Post-patch
#
post-patch:
.if defined(WITH_MSWINDOWS_LICENSE)
	${SORT} ${FILESDIR}/fonts.dir ${FILESDIR}/tahoma.dir > ${FONTS_FILE}
.else
	${CP} ${FILESDIR}/fonts.dir ${FONTS_FILE}
.endif
	${PRINTF} "1i\n%u\n.\nwq\n" `wc -l < ${FONTS_FILE}` | \
		ed -s ${FONTS_FILE}

#
# Pre-install
#
pre-install:
.if defined(WITH_MSWINDOWS_LICENSE)
PLIST_SUB+=	EXTRAFONTS=""
.else
PLIST_SUB+=	EXTRAFONTS="@comment "
.endif

#
# Install
#
do-install:
	${MKDIR} ${FONTSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${FONTS_FILE} ${FONTSDIR}
	${INSTALL_DATA} ${FONTS_FILE} ${FONTSDIR}/fonts.scale
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${DOCSDIR}/LICENSE

#
# Post-install
#
post-install:
	${ECHO_MSG} "===> Running fc-cache"
	-${LOCALBASE}/bin/fc-cache -f -v ${FONTSDIR}
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.post.mk>
