# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	resin
PORTVERSION=	3.1.16
CATEGORIES=	www java
MASTER_SITES=	http://www.caucho.com/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Java-based Application Server, 3.x branch

LICENSE=	GPLv2

USES=		libtool python ssl
USE_JAVA=	yes

# Pass JAVA_HOME as determined by bsd.java.mk
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-java-home=${JAVA_HOME} \
		--with-openssl-lib=${OPENSSLLIB} \
		--with-openssl-include=${OPENSSLINC}

USERS=		www
GROUPS=		www

PLIST_SUB=	APP_NAME=${APP_NAME} \
		APXS=${APXS} \
		GROUPS=${GROUPS} \
		USERS=${USERS}

SUB_LIST=	APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		GROUPS=${GROUPS} \
		LOG_FILE=${LOG_FILE} \
		PID_FILE=${PID_FILE} \
		PORT=${PORT} \
		PYTHON_CMD=${PYTHON_CMD} \
		USERS=${USERS}

# Customizable settings
PORT?=			8080
# Do not use PKGNAMESUFFIX here because version info is already in PORTVERSION
# If we used PKGNAMESUFFIX, the package name would be resin2-2.1.11
APP_NAME_SUFFIX=${PORTVERSION:C/\..*$//}
APP_NAME?=	${PORTNAME}${APP_NAME_SUFFIX}
APP_HOME?=	${PREFIX}/${APP_NAME}
PID_FILE?=	/var/run/${APP_NAME}.pid
LOG_FILE?=	/var/log/${APP_NAME}.log

# Other settings
APXS?=		${LOCALBASE}/sbin/apxs
SUB_FILES=	pkg-message resin3ctl
USE_RC_SUBR=	resin3
NO_ARCH=	yes

.include <bsd.port.options.mk>

post-extract:
	@${MKDIR} ${WRKSRC}/webapps/resin-doc
	@${TAR} xf ${WRKSRC}/webapps/resin-doc.war -C ${WRKSRC}/webapps/resin-doc && ${RM} ${WRKSRC}/webapps/resin-doc.war

post-patch:
	@${REINPLACE_CMD} -e 's|$${resin.home}/conf/app-default.xml|${PREFIX}/etc/${APP_NAME}/app-default.xml|' \
		${WRKSRC}/conf/resin.conf
	@${REINPLACE_CMD} -e 's|ssl23.h|ssl3.h|' ${WRKSRC}/configure

post-build:
	(cd ${WRKSRC}/modules/c/src/resin_os && ${SETENV} ${MAKE_ENV} \
		${MAKE_CMD} ${MAKE_ARGS} install)

# Resin does not handle installation, so proceed now
do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${APP_NAME}
	${INSTALL_DATA} ${WRKSRC}/conf/resin.conf ${STAGEDIR}${PREFIX}/etc/${APP_NAME}/resin.xml.sample
	${INSTALL_DATA} ${WRKSRC}/conf/app-default.xml ${STAGEDIR}${PREFIX}/etc/${APP_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/resin3ctl ${STAGEDIR}${PREFIX}/sbin
	(cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}/webapps)
	(cd ${WRKSRC}/lib  && ${COPYTREE_SHARE} . ${STAGEDIR}${APP_HOME}/lib)

.include <bsd.port.mk>
