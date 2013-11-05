# $FreeBSD$

PORTNAME=	Lohit
PORTVERSION=	20130612
CATEGORIES=	x11-fonts
MASTER_SITES=	https://fedorahosted.org/releases/l/o/lohit/
DISTNAME=	lohit-ttf-${PORTVERSION}

MAINTAINER=	gabor@FreeBSD.org
COMMENT=	Lohit fonts

LICENSE=	OFL11

EXTRACT_SUFX=	.tar.gz
XORG_CAT=	font

FONTLIBPATH=	lib/X11/fonts
FONTROOTDIR=	${PREFIX}/${FONTLIBPATH}
INSTALLS_TTF=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/${DISTNAME:S,.orig,,:S,_,-,}

PLIST_FILES=	${FONTLIBPATH}/${FONTDIR}/Lohit-Assamese.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Bengali.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Devanagari.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Gujarati.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Kannada.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Malayalam.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Marathi.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Nepali.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Oriya.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Punjabi.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Tamil-Classical.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Tamil.ttf \
		${FONTLIBPATH}/${FONTDIR}/Lohit-Telugu.ttf

SUB_LIST=	"FONTPATH=${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

NO_STAGE=	yes
.include <bsd.port.options.mk>

do-configure:
	${DO_NADA}

do-install:
	${ECHO_MSG}
	${CAT} ${PKGMESSAGE}
	${ECHO_MSG}
	${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}

.include <bsd.port.mk>
