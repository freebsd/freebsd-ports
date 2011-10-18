# New ports collection makefile for:	DoulosSIL
# Date created:		October 14 2011
# Whom:			bf <bf@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	DoulosSILCompact
PORTVERSION=	4.110
PORTREVISION=	1
CATEGORIES=	x11-fonts
#unfortunately, the SIL server embeds timestamps in the distfile, so we use a static local copy
.if defined(MAINTAINER_MODE)
MASTER_SITES=	http://scripts.sil.org/ttw/fonts2go.cgi?family=DoulosSIL&pkg=Compact&ver=${PORTVERSION}&filename=/
.else
MASTER_SITES=	LOCAL/bf
.endif
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory

MAINTAINER=	bf@FreeBSD.org
COMMENT=	Doulos SIL TrueType font collection, compact variant

LICENSE=	OFL
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_FILE=	${WRKSRC}/OFL.txt
LICENSE_PERMS=	auto-accept

USE_ZIP=	yes
XORG_CAT=	font

FONTROOTDIR=	${PREFIX}/lib/X11/fonts
INSTALLS_TTF=	yes
NO_BUILD=	yes
USE_TGZ=	yes	#prevent bsd.xorg.mk from setting USE_BZIP

PLIST_FILES=	${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}/${PORTNAME}-R.ttf

.if !defined(NOPORTDOCS)
PORTDOCS=	FONTLOG.txt OFL-FAQ.txt OFL.txt README.txt feat_set_tuned.xml
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
