# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=	resin
PORTVERSION=	3.1.14
PORTREVISION=	1
CATEGORIES=	www java
MASTER_SITES=	http://www.caucho.com/download/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Java-based Application Server, 3.x branch

LICENSE=	GPLv2

OPTIONS_DEFINE=	APACHE22
APACHE22_DESC=	Use Apache 2.2

GNU_CONFIGURE=	yes
USES=		libtool python
USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_OPENSSL=	yes
USE_LDCONFIG=	yes

# Pass JAVA_HOME as determined by bsd.java.mk
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

.include <bsd.port.options.mk>

# Install the Apache plugin if needed
.if ${PORT_OPTIONS:MAPACHE22}
BUILD_DEPENDS+=	${APXS}:www/apache22
CONFIGURE_ARGS+=--with-apxs=${APXS}
PLIST_SUB+=	MOD_DIR=libexec/apache22
# Allow apxs invocations
PLIST_SUB+=	APACHE=""
.else
PLIST_SUB+=	MOD_DIR="@comment "
# Prevent apxs invocations
PLIST_SUB+=	APACHE="@comment "
.endif

post-extract:
	@${MKDIR} ${WRKSRC}/webapps/resin-doc
	@${TAR} xf ${WRKSRC}/webapps/resin-doc.war -C ${WRKSRC}/webapps/resin-doc && ${RM} ${WRKSRC}/webapps/resin-doc.war

post-patch:
	@${REINPLACE_CMD} -e 's|$${resin.home}/conf/app-default.xml|${PREFIX}/etc/${APP_NAME}/app-default.xml|' \
		${WRKSRC}/conf/resin.conf

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
.if ${PORT_OPTIONS:MAPACHE22}
	${APXS} -i -n caucho -a ${WRKSRC}/modules/c/src/apache2/.libs/mod_caucho.so
.endif

.include <bsd.port.mk>
