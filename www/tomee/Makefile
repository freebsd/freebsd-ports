# Created by: Cecile Neu <neu@mycontrol.de>
# $FreeBSD$

PORTNAME=	tomee
PORTVERSION=	1.7.4
CATEGORIES=	www java
MASTER_SITES=	APACHE/tomee/tomee-${PORTVERSION}
DISTNAME=	apache-${PORTNAME}-${PORTVERSION}-webprofile

MAINTAINER=	neu@mycontrol.de
COMMENT=	Open-source Java EE Container by Apache

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe
CPE_VENDOR=	apache

USE_JAVA=	yes
NO_ARCH=	yes
NO_BUILD=	yes

USE_RC_SUBR=	${PKGBASE}

TOMEE_SUBDIR?=	${DISTNAME:R}
TOMEE_HOME=	${PREFIX}/${TOMEE_SUBDIR}
TOMEE_CONF_FILES=	\
		catalina.policy catalina.properties context.xml logging.properties \
		server.xml tomcat-users.xml web.xml tomee.xml system.properties
PLIST_SUB=	T=${TOMEE_SUBDIR} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

SUB_LIST=	TOMEE_HOME=${TOMEE_HOME} \
		TOMEE_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}
WRKSRC=		${WRKDIR}/apache-${PORTNAME}-webprofile-${PORTVERSION}

.include <bsd.port.pre.mk>

post-patch:
	@${FIND} ${WRKSRC} -name '*.bat' -delete
	@${FIND} ${WRKSRC} -name '*.exe' -delete
	@${FIND} ${WRKSRC} -name '*.bat.original' -delete
.for f in ${TOMEE_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.sample
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${TOMEE_HOME}/logs
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMEE_HOME}
	${FIND} ${STAGEDIR}${TOMEE_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.include <bsd.port.post.mk>
