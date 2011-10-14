# New ports collection makefile for:	CharisSIL
# Date created:		March 3 2011
# Whom:			bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	CharisSIL
PORTVERSION=	4.110
CATEGORIES=	x11-fonts
MASTER_SITES=	http://scripts.sil.org/cms/scripts/render_download.php?&format=file&media_id=${MEDIA_ID}&filename=/ \
		LOCAL/bf
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Charis SIL TrueType font collection

LICENSE=	OFL
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_FILE=	${WRKSRC}/OFL.txt
LICENSE_PERMS=	auto-accept

USE_ZIP=	yes
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts
INSTALLS_TTF=	yes
MEDIA_ID=	${DISTNAME}${EXTRACT_SUFX}
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

.for type in B BI I R
PLIST_FILES+=	${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}/${PORTNAME}-${type}.ttf
.endfor

.if !defined(NOPORTDOCS)
PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt
.endif

SUB_LIST=	DIR="${FONTROOTDIR}/${FONTDIR}"
SUB_FILES=	pkg-message

do-configure:
	@${DO_NADA}

do-install:
	@${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} *.ttf ${FONTROOTDIR}/${FONTDIR})
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@(cd ${WRKSRC} ; ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR})
.endif
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
