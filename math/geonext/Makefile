# New ports collection makefile for:	geonext
# Date created:		Mon Dec  6 19:56:58 CET 2004
# Whom:			Andreas Fehlner (fehlner@gmx.de)
#
# $FreeBSD$
#

PORTNAME=	geonext
PORTVERSION=	1.11
CATEGORIES=	math graphics java
MASTER_SITES=	http://geonext.uni-bayreuth.de/data/download/\
		http://home.arcor.de/fehlner/inhalt/download/\
		http://home.arcor.de/teambushido/
DISTNAME=	geonext.${PORTVERSION}

MAINTAINER=	fehlner@gmx.de
COMMENT?=	Interactive (dynamic) elementary Geometry Software

WRKSRC=		${WRKDIR}/geonext_install
NO_BUILD=	yes
USE_ZIP=	yes
USE_JAVA=	yes
JAVA_VERSION=	1.4
DATA=	cacerts didmat.crt geonext.html geonext.jar license.txt index.html
IMG=	g.gif gn.gif gni.gif geoint.png pixel.gif gx.gif gxt.gif ubt.gif x.ico

# available languages: bg, cz, de, en, es, fr, hu, sk, ja, ro
# default: en
.if !defined(WITH_LANG)
WITH_LANG=	en
.endif

# For the slave ports
LA=	language=${WITH_LANG}
.if ${WITH_LANG} != "en"
PKGNAMEPREFIX=	${WITH_LANG}-
.endif

PLIST_SUB=	LANG=${WITH_LANG}
GLOCATE=	${DATADIR}-${WITH_LANG}

.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_LANG=lang     - Choose language"
	@${ECHO_MSG} "Default language: en"
	@${ECHO_MSG} "available languages: en, fr, bg, cz, de, es, hu, sk, ja, ro"
	@${ECHO_MSG} "example: make WITH_LANG=fr install"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "Your current setting is:"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_LANG=${WITH_LANG}"
	@${ECHO_MSG} ""

do-install::
	${MKDIR} ${GLOCATE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${DATA} ${GLOCATE}
	cd ${WRKSRC} && ${INSTALL_DATA} ${IMG} ${GLOCATE}
	@${ECHO_MSG} '#!/bin/sh' > ${GLOCATE}/${PORTNAME}-${WITH_LANG}
	@${ECHO_MSG} '${JAVA} -cp ${GLOCATE}/geonext.jar geonext/Geonext ${LA} &' \
	 >>${GLOCATE}/${PORTNAME}-${WITH_LANG}
	${CHMOD} a+x ${GLOCATE}/${PORTNAME}-${WITH_LANG}
	${INSTALL_SCRIPT} ${GLOCATE}/geonext-${WITH_LANG} ${PREFIX}/bin

.include <bsd.port.post.mk>
