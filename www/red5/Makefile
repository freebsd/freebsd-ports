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
MASTER_SITES=	http://www.red5.org/downloads/0_9/ \
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

pre-install:
	@${REINPLACE_CMD} -e 's/0.0.0.0/127.0.0.1/' ${WRKSRC}/conf/red5.properties

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

.include <bsd.port.mk>
