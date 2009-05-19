# New ports collection makefile for:	cmps
# Date created:		11 September 1998
# Whom:			giffunip
#
# $FreeBSD$
#

PORTNAME=	cmpsfont
PORTVERSION=	1.0
PORTREVISION=	6
CATEGORIES=	print x11-fonts
MASTER_SITES=	ftp://ftp.ams.org/pub/tex/psfonts/cm/
DISTNAME=	cmps
EXTRACT_SUFX=	-unix.tar.gz

MAINTAINER=	hrs@FreeBSD.org
COMMENT=	Computer Modern PostScript Fonts (Adobe Type 1 format)

.if !defined(WITHOUT_X11)
BUILD_DEPENDS=	${LOCALBASE}/bin/type1inst:${PORTSDIR}/x11-fonts/p5-type1inst
.endif

WRKSRC=		${WRKDIR}/cmpsfont
PLIST_SUB=	PLIST_X11=${PLIST_X11}

.if !defined(WITHOUT_X11)
PLIST_X11=	""
SUB_FILES=	pkg-message
.else
PLIST_X11=	"@comment "
.endif

FONTSDIR=	share/fonts/${PORTNAME}

do-build:
.if !defined(WITHOUT_X11)
	${TOUCH} ${WRKSRC}/pfb/fonts.dir
	(cd ${WRKSRC}/pfb; ${LOCALBASE}/bin/type1inst -nolog -quiet)
.else
	@${DO_NADA}
.endif

do-install:
	${MKDIR} ${PREFIX}/${FONTSDIR}/afm
	${INSTALL_DATA} ${WRKSRC}/afm/* ${PREFIX}/${FONTSDIR}/afm
	${MKDIR} ${PREFIX}/${FONTSDIR}/type1
	${INSTALL_DATA} ${WRKSRC}/pfb/* ${PREFIX}/${FONTSDIR}/type1
	${INSTALL_DATA} \
		${WRKSRC}/README ${WRKSRC}/cmsample.tex \
		${PREFIX}/${FONTSDIR}/

.if !defined(WITHOUT_X11)
post-install:
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
