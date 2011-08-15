# New ports collection makefile for:    devel/red5
# Date created:         14 March 2008
# Whom:                 wenheping@gmail.com
#
# $FreeBSD$
#

PORTNAME=	red5
PORTVERSION=	0.9.1
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://trac.red5.org/downloads/0_9/ \
		http://red5.rmdir.fr/

MAINTAINER=	joris.dedieu@gmail.com
COMMENT=	Red5 is an Open Source Flash Server

USE_JAVA=	yes
NO_BUILD=	yes
USE_RC_SUBR=	red5

RED5_USER?=	${WWWOWN}
RED5_GRP?=	${WWWGRP}
RED5_HOME?=	${PREFIX}/${PORTNAME}

SUB_LIST+=	RED5_USER=${RED5_USER} RED5_HOME=${RED5_HOME}

post-patch:
	@${REINPLACE_CMD} -e 's/0.0.0.0/127.0.0.1/' ${WRKSRC}/conf/red5.properties
	(cd ${WRKSRC}/conf \
		&& for file in `find . -type f` ; \
		   do	${MV} $$file $$file.sample ; \
		done)
.for webappssubdir in installer root
	(cd ${WRKSRC}/webapps/${webappssubdir}/WEB-INF \
		&& for file in * ; \
		   do	${MV} $$file $$file.sample ; \
		done)
.endfor

do-install:
	${MKDIR} ${RED5_HOME}/conf ${RED5_HOME}/lib ${RED5_HOME}/webapps ${RED5_HOME}/log
	${INSTALL} ${WRKSRC}/boot.jar ${RED5_HOME}
	${INSTALL} ${WRKSRC}/red5.jar ${RED5_HOME}
	(cd ${WRKSRC}/conf && ${COPYTREE_SHARE} \* ${RED5_HOME}/conf)
	(cd ${WRKSRC}/lib && ${COPYTREE_SHARE} \* ${RED5_HOME}/lib)
	(cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} \* ${RED5_HOME}/webapps)
	${CHOWN} -R  ${RED5_USER}:${RED5_GRP} ${RED5_HOME}

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} \* ${DOCSDIR})
.endif
	@${ECHO_CMD} '@exec ${CHOWN} -R ${RED5_USER}:${RED5_GRP} ${RED5_HOME}' \
		>> ${TMPPLIST}
	for file in `find ${RED5_HOME}/conf -type f -regex '.*\.sample$$'` ; \
	  do	[ -f $${file%.sample} ] || ${CP} -p $$file $${file%.sample} ; \
	  done
	for file in ${RED5_HOME}/webapps/root/WEB-INF/*.sample ${RED5_HOME}/webapps/installer/WEB-INF/*.sample ; \
	  do	[ -f $${file%.sample} ] || ${CP} -p $$file $${file%.sample} ; \
	  done

.include <bsd.port.mk>
