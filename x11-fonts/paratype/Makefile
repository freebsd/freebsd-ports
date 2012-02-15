# New ports collection makefile for:	paratype-fonts
# Date created:		05 March 2011
# Whom:			Alexey Illarionov <littlesavage@rambler.ru>
#
# $FreeBSD$
#

PORTNAME=	paratype
PORTVERSION=	2.004
PORTREVISION=	3
CATEGORIES=	x11-fonts
MASTER_SITES=	http://www.fontstock.com/public/
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory
DISTFILES=	PTSansOFL.zip PTSerifOFL.zip PTMonoOFL.zip

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	ParaType font collection for the languages of Russia

LICENSE=	OFL
LICENSE_FILE=	${WRKSRC}/PTSansPTSerifOFL.txt
LICENSE_NAME=	SIL Open Font License (OFL)
LICENSE_PERMS=	auto-accept

INSTALLS_TTF=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_TGZ=	yes
USE_ZIP=	yes
XORG_CAT=	font

FONTDIR=	ParaType
FONTROOTDIR=	${PREFIX}/lib/X11/fonts
PLIST_SUB=	FONTDIR="${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}"
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR="${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}"

do-configure:
	@${DO_NADA}

do-install:
	@${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}/
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
