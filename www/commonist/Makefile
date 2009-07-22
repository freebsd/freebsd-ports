# New ports collection makefile for:	commonist
# Date created:		2008-06-17
# Whom:			Marcin Cieslak <saper@SYSTEM.PL>
#
# $FreeBSD$
#

PORTNAME=	commonist
PORTVERSION=	0.3.40
CATEGORIES=	www java
MASTER_SITES=	http://djini.de/software/commonist/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Easy upload of images to Wikimedia Commons and Mediawiki

TARGET_JAR=	${JAVAJARDIR}/${PORTNAME}.jar
USE_ZIP=	yes
USE_JAVA=	1.5+
JAVA_EXTRACT=	yes
USE_ANT=	yes
ALL_TARGET=	jar
MAKE_FLAGS+=	-verbose
MAKE_ARGS+=	-Djar.lib.dir=${WRKSRC}/build/jar -Dtarget.name=${WRKSRC}/build/jar/${PORTNAME}.jar \
		-Djavacc.home=${JAVAJARDIR}

SUB_FILES+=	commonist
SUB_LIST+=	TARGET_JAR=${TARGET_JAR}

BUILD_DEPENDS+=	${JAVAJARDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVAJARDIR}/bsh.jar:${PORTSDIR}/lang/bsh \
		${JAVAJARDIR}/javacc.jar:${PORTSDIR}/textproc/javacc

RUN_DEPENDS+=	${JAVAJARDIR}/commons-httpclient.jar:${PORTSDIR}/java/jakarta-commons-httpclient \
		${JAVAJARDIR}/bsh.jar:${PORTSDIR}/lang/bsh

.include <bsd.port.pre.mk>

post-extract:
	(cd ${WRKSRC} && ${JAR} xf lib/lib-util-src.jar src)
	(cd ${WRKSRC} && ${JAR} xf lib/mwapi-src.jar src)
	(cd ${WRKSRC} && ${JAR} xf lib/minibpp-src.jar source)
	(cd ${WRKSRC}/source && ${FIND} * -print | ${CPIO} -pdmu ${WRKSRC}/src)

post-patch:
	${REINPLACE_CMD} -e "s#%%ETCDIR%%#${ETCDIR}#" ${WRKSRC}/src/net/psammead/commonist/Main.java

pre-build:
	(cd ${WRKSRC} && ${ANT} clean)
	${MKDIR} ${WRKSRC}/build/classes
	${JAR} tf ${WRKSRC}/lib/mwapi.jar net/psammead/mwapi/config | ${EGREP} '(site|family|list)' > ${WRKSRC}/configfiles
	(cd ${WRKSRC}/build/classes && ${JAR} xf ${WRKSRC}/lib/mwapi.jar `${CAT} ${WRKSRC}/configfiles`)

do-install:
	${MKDIR} ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${WRKDIR}/commonist ${PREFIX}/bin
	${INSTALL_DATA}	${WRKSRC}/build/jar/${PORTNAME}.jar ${TARGET_JAR}
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/etc/startup.bsh ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/build/classes/net/psammead/mwapi/config/commons.family ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/build/classes/net/psammead/mwapi/config/commons.site ${EXAMPLESDIR}
.endif
	${MKDIR} ${ETCDIR}
.for f in gallery_commons.bpp image_default.bpp messages_fr.properties \
		image_commons.bpp gallery_default.bpp licenses.txt messages_en.properties \
		messages_sk.properties messages_de.properties
		${INSTALL_DATA} ${WRKSRC}/etc/${f} ${ETCDIR}
.endfor

.include <bsd.port.post.mk>
