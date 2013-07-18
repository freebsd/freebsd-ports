# $FreeBSD$

PORTNAME=	red5
PORTVERSION=	1.0.1
CATEGORIES=	www java
MASTER_SITES=	http://www.red5.org/downloads/red5/1_0_1/ \
		http://red5.rmdir.fr/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Red5 is an Open Source Flash Server

USE_JAVA=	yes
NO_BUILD=	yes
USE_RC_SUBR=	red5
WRKSRC=         ${WRKDIR}/red5-server-1.0

RED5_USER?=	${WWWOWN}
RED5_GRP?=	${WWWGRP}
RED5_HOME?=	${PREFIX}/${PORTNAME}

SUB_LIST+=	RED5_USER=${RED5_USER} RED5_HOME=${RED5_HOME}

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
	${MKDIR} ${RED5_HOME}/conf ${RED5_HOME}/lib ${RED5_HOME}/webapps ${RED5_HOME}/log ${RED5_HOME}/plugins
	${INSTALL} ${WRKSRC}/red5-server-1.0-bootstrap.jar ${RED5_HOME}
	${INSTALL} ${WRKSRC}/red5-server-1.0.jar ${RED5_HOME}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} \* ${RED5_HOME}/conf)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${RED5_HOME}/lib)
	(cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} \* ${RED5_HOME}/webapps)
	(cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} \* ${RED5_HOME}/plugins)
	${CHOWN} -R  ${RED5_USER}:${RED5_GRP} ${RED5_HOME}

post-install:
	@${ECHO_CMD} '@exec ${CHOWN} -R ${RED5_USER}:${RED5_GRP} ${RED5_HOME}' \
		>> ${TMPPLIST}
	for conf in `find ${RED5_HOME}/conf -type f -regex '.*\.sample$$'` ; \
	  do	[ -f $${conf%.sample} ] || ${CP} -p $$conf $${conf%.sample} ; \
	  done
	for conf in ${RED5_HOME}/webapps/root/WEB-INF/*.sample ${RED5_HOME}/webapps/installer/WEB-INF/*.sample ${RED5_HOME}/webapps/red5-default.xml.sample; \
	  do	[ -f $${conf%.sample} ] || ${CP} -p $$conf $${conf%.sample} ; \
	  done

.include <bsd.port.mk>
