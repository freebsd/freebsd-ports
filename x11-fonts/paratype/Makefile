# Created by: Alexey Illarionov <littlesavage@rambler.ru>
# $FreeBSD$

PORTNAME=	paratype
PORTVERSION=	2.004
PORTREVISION=	4
CATEGORIES=	x11-fonts
MASTER_SITES=	http://paratype.0xdc.ru/
MASTER_SITE_SUBDIR=	#prevent bsd.xorg.mk from setting a default subdirectory
DISTFILES=	PTSansOFL-2.004.zip PTSerifOFL-1.000.zip PTMonoOFL-1.002_1.zip

MAINTAINER=	littlesavage@rambler.ru
COMMENT=	ParaType font collection for the languages of Russia

LICENSE=	OFL11

INSTALLS_TTF=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes
USE_TGZ=	yes
USES=		zip
XORG_CAT=	font

FONTDIR=	ParaType
FONTROOTDIR=	${PREFIX}/lib/X11/fonts
PLIST_SUB=	FONTDIR="${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}"
SUB_FILES=	pkg-message
SUB_LIST=	FONTDIR="${FONTROOTDIR:S/${PREFIX}\///}/${FONTDIR}"

NO_STAGE=	yes
do-configure:
	@${DO_NADA}

do-install:
	@${MKDIR} ${FONTROOTDIR}/${FONTDIR}
	@${INSTALL_DATA} ${WRKSRC}/*.ttf ${FONTROOTDIR}/${FONTDIR}/
	@${ECHO_MSG}
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG}

.include <bsd.port.mk>
