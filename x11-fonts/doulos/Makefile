# New ports collection makefile for:	DoulosSIL
# Date created:		March 3 2011
# Whom:			bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DoulosSIL
PORTVERSION=	4.106
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=${MEDIA_ID}&filename=/
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory
DISTNAME=	${PORTNAME}${PORTVERSION}

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Doulos SIL TrueType font collection

USE_ZIP=	yes
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts/${FONTDIR}
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}b${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP
WRKSRC=		${WRKDIR}/${PORTNAME}

LICENSE=	OFL
LICENSE_FILE=	${WRKSRC}/OFL.txt
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_PERMS=	auto-accept

PLIST_FILES=	${FONTROOTDIR:S/${PREFIX}\///}/${PORTNAME}R.ttf

.if !defined(NOPORTDOCS)
PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt
.endif

SUB_LIST=	FONTROOTDIR="${FONTROOTDIR}"
SUB_FILES=	pkg-message

do-configure:
	@${DO_NADA}

do-install:
	@${MKDIR} ${FONTROOTDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${FONTROOTDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
