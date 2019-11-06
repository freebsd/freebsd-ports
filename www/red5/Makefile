# $FreeBSD$

PORTNAME=	red5
PORTVERSION=	1.0.1
CATEGORIES=	www java
MASTER_SITES=	http://www.red5.org/downloads/red5/1_0_1/ \
		http://red5.rmdir.fr/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Red5 is an Open Source Flash Server

BROKEN=		unfetchable

USE_JAVA=	yes
NO_BUILD=	yes
NO_ARCH=	yes
USE_RC_SUBR=	red5
WRKSRC=		${WRKDIR}/red5-server-1.0

RED5_USER?=	${WWWOWN}
RED5_GRP?=	${WWWGRP}
RED5_HOME?=	${PREFIX}/${PORTNAME}

SUB_LIST+=	RED5_USER=${RED5_USER} RED5_HOME=${RED5_HOME}
PLIST_SUB=	RED5_USER=${RED5_USER} RED5_GRP=${RED5_GRP}

post-patch:
	@${REINPLACE_CMD} -e 's/host=0.0.0.0/host=127.0.0.1/' ${WRKSRC}/conf/red5.properties
	@${RM} ${WRKSRC}/conf/red5.properties.bak
	(cd ${WRKSRC}/conf \
		&& for conf in `find . -type f` ; \
		   do	${MV} $$conf $$conf.sample ; \
		done)
.for webappssubdir in installer root live vod
	(cd ${WRKSRC}/webapps/${webappssubdir}/WEB-INF \
		&& for conf in * ; \
		   do	${MV} $$conf $$conf.sample ; \
		done)
.endfor
		${MV} ${WRKSRC}/webapps/red5-default.xml ${WRKSRC}/webapps/red5-default.xml.sample

do-install:
	${MKDIR} ${STAGEDIR}${RED5_HOME}/conf ${STAGEDIR}${RED5_HOME}/lib ${STAGEDIR}${RED5_HOME}/webapps ${STAGEDIR}${RED5_HOME}/log ${STAGEDIR}${RED5_HOME}/plugins
	${INSTALL} ${WRKSRC}/red5-server-1.0-bootstrap.jar ${STAGEDIR}${RED5_HOME}
	${INSTALL} ${WRKSRC}/red5-server-1.0.jar ${STAGEDIR}${RED5_HOME}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} \* ${STAGEDIR}${RED5_HOME}/conf)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${STAGEDIR}${RED5_HOME}/lib)
	(cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} \* ${STAGEDIR}${RED5_HOME}/webapps)
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} \* ${STAGEDIR}${RED5_HOME}/plugins)

.include <bsd.port.mk>
