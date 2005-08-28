# New ports collection makefile for:	TrueType core fonts for the Web
# Date created:		12 Jan 2001
# Whom:			Konstantinos Konstantinidis <kkonstan@daemon.gr>
#
# $FreeBSD$
#

PORTNAME=	webfonts
PORTVERSION=	0.21
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	${MASTER_SITE_NETBSD:S/%SUBDIR%/ms-ttf/} \
	${MASTER_SITE_SOURCEFORGE:S/%SUBDIR%/corefonts/} \
	ftp://ftp.uni-koeln.de/pc/win32/msoft-95/ \
	ftp://ftp.extra.ouh.nl/studie/alg/hulp/win/fonts/ \
	ftp://ftp.vn.ua/pub/win/freefont/ \
	ftp://ftp.vsu.ru/pub/tex/font-packs/mscore/ \
	ftp://ftp.directnet.ru/pub/fonts-win/ \
	ftp://ftp.sinn.ru/pub/win95/fonts/ \
	ftp://ftp.lexa.ru/pub/mirrors/ftp.vsu.ru/pub/tex/font-packs/mscore/ \
	ftp://ftp.botik.ru/rented/znamensk/distributions/ftp.vsu.ru/pub/tex/font-packs/mscore/
DISTFILES=	andale32.exe trebuc32.exe georgi32.exe verdan32.exe \
		comic32.exe arialb32.exe impact32.exe arial32.exe \
		times32.exe courie32.exe webdin32.exe
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	kkonstan@duth.gr
COMMENT=	TrueType core fonts for the Web

EXTRACT_DEPENDS=cabextract:${PORTSDIR}/archivers/cabextract

USE_X_PREFIX=	yes

NO_BUILD=	yes
NO_CDROM=	"Restrictive license - cannot sell for profit"
NO_PACKAGE=	"Restrictive license - cannot distribute in modified form"

EXTRACT_CMD=		${LOCALBASE}/bin/cabextract
EXTRACT_BEFORE_ARGS=	--lowercase --quiet
EXTRACT_AFTER_ARGS=	-d ${WRKSRC}

#
# Local variables
#
FONTNAME=	${PORTNAME}
FONTSDIR?=	${PREFIX}/lib/X11/fonts/${FONTNAME}
TTFONTSDIR?=	${X11BASE}/lib/X11/fonts/TrueType

PLIST_SUB=	FONTNAME="${FONTNAME}" \
		FONTSDIR="${FONTSDIR:S|${PREFIX}/||}" \
		TTFONTSDIR="${TTFONTSDIR:S|${X11BASE}/||}"

MSG_FILE=	${PKGDIR}/pkg-message
PKGMESSAGE=	${WRKDIR}/pkg-message

.include <bsd.port.pre.mk>

.if ${X_WINDOW_SYSTEM:L} == xfree86-3
RUN_DEPENDS=	xfstt:${PORTSDIR}/x11-servers/Xfstt
PLIST_SUB+=	FCACHE="@comment " \
		OLDXF86=""
.else
BUILD_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
RUN_DEPENDS=	fc-cache:${PORTSDIR}/x11-fonts/fontconfig
PLIST_SUB+=	FCACHE="" \
		OLDXF86="@comment "
.endif

.SILENT:

#
# Post-extract
#
post-extract:
	${RM} -f ${WRKSRC}/*.dll ${WRKSRC}/*.exe ${WRKSRC}/*.inf

#
# Post-patch
#
post-patch:
	${SED} 's|%%FONTSDIR%%|${FONTSDIR}|g' ${MSG_FILE} > ${PKGMESSAGE}

#
# Install
#
do-install:
	${MKDIR} ${FONTSDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${FONTSDIR}/fonts.scale
	${INSTALL_DATA} ${WRKSRC}/licen.txt ${DOCSDIR}/LICENSE
.if ${X_WINDOW_SYSTEM:L} == xfree86-3
	${LN} -fs ${FONTSDIR} ${TTFONTSDIR}/${FONTNAME}
.endif

#
# Post-install
#
post-install:
.if ${X_WINDOW_SYSTEM:L} != xfree86-3
	${ECHO_MSG} "===> Running fc-cache"
	-${X11BASE}/bin/fc-cache -f -v ${FONTSDIR}
.endif
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}

.include <bsd.port.post.mk>
