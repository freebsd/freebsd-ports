PORTNAME=	tomee
DISTVERSION=	8.0.16
CATEGORIES=	www java
MASTER_SITES=	https://archive.apache.org/dist/${PORTNAME}/${PORTNAME}-${DISTVERSION}/
DISTNAME=	apache-${PORTNAME}-${DISTVERSION}-webprofile

MAINTAINER=	neu@mycontrol.de
COMMENT=	Open-source Java EE Container by Apache
WWW=		https://tomee.apache.org/

LICENSE=	APACHE20

RUN_DEPENDS=	jsvc:devel/apache-commons-daemon

USES=		cpe
CPE_VENDOR=	apache
USE_JAVA=	yes
USE_RC_SUBR=	${PKGBASE}

EXTRACT_AFTER_ARGS=	--exclude *.bat \
			--exclude *.bat.original \
			--exclude *.exe \
			--no-same-owner --no-same-permissions
NO_ARCH=	yes
NO_BUILD=	yes
SUB_LIST=	TOMEE_HOME=${TOMEE_HOME} \
		TOMEE_USER=${WWWOWN} \
		JAVA_HOME=${JAVA_HOME}

WRKSRC=		${WRKDIR}/apache-${PORTNAME}-webprofile-${DISTVERSION}

PLIST_SUB=	T=${TOMEE_SUBDIR} \
		WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

TOMEE_SUBDIR?=	${DISTNAME:R}
TOMEE_HOME=	${PREFIX}/${TOMEE_SUBDIR}
TOMEE_CONF_FILES=	\
		catalina.policy catalina.properties context.xml jaspic-providers.xml \
		logging.properties server.xml tomcat-users.xml web.xml tomee.xml \
		system.properties

.include <bsd.port.pre.mk>

post-patch:
.for f in ${TOMEE_CONF_FILES}
	@${MV} ${WRKSRC}/conf/${f} ${WRKSRC}/conf/${f}.sample
.endfor

do-install:
	${MKDIR} ${STAGEDIR}${TOMEE_HOME}/logs
	${CP} -R ${WRKSRC}/* ${STAGEDIR}${TOMEE_HOME}
	${FIND} ${STAGEDIR}${TOMEE_HOME} -type d -print0 | ${XARGS} -0 ${CHMOD} 755

.include <bsd.port.post.mk>
