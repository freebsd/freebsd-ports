# Created by: Andreas Fehlner (fehlner@gmx.de)
# $FreeBSD$

PORTNAME=	geonext
PORTVERSION=	1.71
CATEGORIES+=	math graphics java
MASTER_SITES=	http://geonext.uni-bayreuth.de/data/download/\
		http://home.arcor.de/fehlner/site/download/\
		http://home.arcor.de/teambushido/fbsd_ports/
DISTNAME=	geonext.${PORTVERSION}

MAINTAINER=	fehlner@gmx.de
COMMENT=	Interactive (dynamic) elementary Geometry Software

WRKSRC=		${WRKDIR}/geonext_install
NO_BUILD=	yes
USES=		zip
USE_JAVA=	yes
JAVA_VERSION=	1.6+
DATA=	cacerts didmat.crt geonext.html geonext.jar license.txt index.html\
	geonext-batik.jar help.jar help_fr.jar help_de.jar help_it.jar \
	help_uk.jar

IMG=	geoint.png gxt.gif ubt.gif x.ico

# available languages:	al, bg, cz, de, en, es, fr, hu, it, ja, lv,
# 			pt_BR, ro, ru, sk, sl, uk
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

NO_STAGE=	yes
.include <bsd.port.pre.mk>

pre-everything::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "N - O - T - E"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_LANG=lang     - Choose language"
	@${ECHO_MSG} "Default language: en"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "available languages: al, bg, cz, de, en, es, fr, "
	@${ECHO_MSG} "hu, it, ja, lv, pt_BR, ro, ru, sk, sl, uk,..."
	@${ECHO_MSG} "-------------------------------------------------"
	@${ECHO_MSG} ""
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
