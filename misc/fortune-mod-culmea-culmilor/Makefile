# New ports collection makefile for:	fortune-mod-culmea-culmilor
# Date created:				2005-11-18
# Whom:                Ion-Mihai "IOnut" Tetcu <itetcu@people.tecnik93.com>
#
# $FreeBSD$
# $Id: Makefile,v 1.9 2005/11/19 20:35:11 itetcu Rel $
#

PORTNAME=	fortune-mod-culmea-culmilor
PORTVERSION=	2005.11.18
CATEGORIES=	misc 	# should / will (also) be romanian
MASTER_SITES=	http://people.tecnik93.com/~itetcu/FreeBSD/ports/${PORTNAME}/sources/

MAINTAINER=	itetcu@people.tecnik93.com
COMMENT=	Romanian "Culmea culmilor" jokes (in romanian)

NO_WRKSUBDIR=	yes

_STRFILE=	/usr/games/strfile
_FORTUNE_DIR=	share/games/fortune
FORTUNE_DIR?=	${PREFIX}/${_FORTUNE_DIR}
FORTUNE_FILE=	${PORTNAME:S/fortune-mod-//}
FORTUNE_FILE_O=	${FORTUNE_FILE}-o

PLIST_FILES=	${_FORTUNE_DIR}/${FORTUNE_FILE} ${_FORTUNE_DIR}/${FORTUNE_FILE}.dat
.if exists(${WRKSRC}/${PORTNAME}-o)
PLIST_FILES+=	${_FORTUNE_DIR}/${FORTUNE_FILE_O} ${_FORTUNE_DIR}/${FORTUNE_FILE_O}.dat
.endif

SUB_FILES+=	pkg-message
SUB_LIST+=	FORTUNE_DIR=${FORTUNE_DIR} FORTUNE_FILE=${FORTUNE_FILE}

do-build:
	cd ${WRKSRC} && ${_STRFILE} ${PORTNAME}
.	if exists(${WRKSRC}/${PORTNAME}-o)
		cd ${WRKSRC} && ${_STRFILE} ${PORTNAME}-o
.	endif

do-install:
	@${MKDIR} ${FORTUNE_DIR}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME} ${FORTUNE_DIR}/${FORTUNE_FILE}
	@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.dat ${FORTUNE_DIR}/${FORTUNE_FILE}.dat
.	if exists(${WRKSRC}/${PORTNAME}-o)
		@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-o ${FORTUNE_DIR}/${FORTUNE_FILE_O}
		@${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-o.dat {FORTUNE_DIR}/${FORTUNE_FILE_O}.dat
.	endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
