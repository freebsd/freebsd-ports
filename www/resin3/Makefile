# Created by: Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# $FreeBSD$

PORTNAME=		resin
PORTVERSION=		3.1.13
CATEGORIES=		www java
MASTER_SITES=		http://www.caucho.com/download/

MAINTAINER=		5u623l20@gmail.com
COMMENT=		Java-based Application Server, 3.x branch

OPTIONS_DEFINE=	APACHE22
APACHE22_DESC=	Use Apache 2.2

.include <bsd.port.options.mk>

USE_JAVA=		yes
JAVA_VERSION=		1.6+
HAS_CONFIGURE=		yes
USE_PYTHON=		yes
USE_OPENSSL=		yes
USE_AUTOTOOLS=		libtool
USE_LDCONFIG=		yes

USERS=	www
GROUPS=	www
SHAREOWN=	www
SHAREGRP=	www

# Customizable settings
PORT?=			8080
# Do not use PKGNAMESUFFIX here because version info is already in PORTVERSION
# If we used PKGNAMESUFFIX, the package name would be resin2-2.1.11
APP_NAME_SUFFIX=	${PORTVERSION:C/\..*$//}
APP_NAME?=		${PORTNAME}${APP_NAME_SUFFIX}
LATEST_LINK=		${APP_NAME}
APP_HOME?=		${PREFIX}/${APP_NAME}
PID_FILE?=		${APP_HOME}/${APP_NAME}.pid
LOG_FILE?=		${APP_HOME}/${APP_NAME}.log

# Other settings
APXS?=			${LOCALBASE}/sbin/apxs
SUB_FILES=		pkg-message resin3ctl
USE_RC_SUBR=	resin3

.include <bsd.port.pre.mk>

# Pass JAVA_HOME as determined by bsd.java.mk
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME} \
			--with-openssl-lib=${OPENSSLLIB} \
			--with-openssl-include=${OPENSSLINC}
LDFLAGS+=		-L${OPENSSLLIB} -lcrypto -lssl
# We need to link with cc instead of ld for the FreeBSD specific options used
# by threading libraries
CONFIGURE_ENV=		LD=${CC} PTHREAD_LIBS="${PTHREAD_LIBS}" LIBTOOL=${LIBTOOL}

# Install the Apache plugin if needed
.if ${PORT_OPTIONS:MAPACHE22}
BUILD_DEPENDS+=		${APXS}:${PORTSDIR}/www/apache22
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=		MOD_DIR=libexec/apache22
# Allow apxs invocations
PLIST_SUB+=		APACHE=""
.else
PLIST_SUB+=		MOD_DIR="@comment "
# Prevent apxs invocations
PLIST_SUB+=		APACHE="@comment "
.endif

PLIST_SUB+=	APP_NAME=${APP_NAME} \
		APXS=${APXS} \
		GROUPS=${GROUPS} \
		USERS=${USERS}

SUB_LIST=	APP_HOME=${APP_HOME} \
		APP_NAME=${APP_NAME} \
		GROUPS=${GROUPS} \
		LOCALBASE=${LOCALBASE} \
		LOG_FILE=${LOG_FILE} \
		PID_FILE=${PID_FILE} \
		PORT=${PORT} \
		PREFIX=${PREFIX} \
		PYTHON_CMD=${PYTHON_CMD} \
		USERS=${USERS}

post-extract:
	@${MKDIR} ${WRKSRC}/webapps/resin-doc
	@${TAR} xf ${WRKSRC}/webapps/resin-doc.war -C ${WRKSRC}/webapps/resin-doc && ${RM} ${WRKSRC}/webapps/resin-doc.war

post-patch:
	@${REINPLACE_CMD} -e 's|$${resin.home}/conf/app-default.xml|${PREFIX}/etc/${APP_NAME}/app-default.xml|' \
		${WRKSRC}/conf/resin.conf

post-build:
	cd ${WRKSRC}/modules/c/src/resin_os && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} install

# Resin does not handle installation, so proceed now
do-install:
.for i in ${APP_HOME} ${APP_HOME}/lib ${PREFIX}/etc/${APP_NAME}
	@install -d -g ${WWWOWN} -o ${WWWGRP} ${i}
.endfor
	if [ ! -e ${PREFIX}/etc/${APP_NAME}/resin.xml ]; then \
			${ECHO_MSG} "   Installing local configuration file: ${PREFIX}/etc/${APP_NAME}/resin.xml" ;\
			${INSTALL_DATA} ${WRKSRC}/conf/resin.conf ${PREFIX}/etc/${APP_NAME}/resin.xml ;\
	else \
		${ECHO_MSG} "   Preserving local configuration file: ${PREFIX}/etc/${APP_NAME}/resin.xml" ;\
	fi
	${INSTALL_DATA} ${WRKSRC}/conf/resin.conf ${PREFIX}/etc/${APP_NAME}/resin.xml-dist
	${INSTALL_DATA} ${WRKSRC}/conf/app-default.xml ${PREFIX}/etc/${APP_NAME}
	${INSTALL_SCRIPT} ${WRKDIR}/resin3ctl ${PREFIX}/sbin
	cd ${WRKSRC}/webapps && ${COPYTREE_SHARE} \* ${APP_HOME}/webapps
	cd ${WRKSRC}/lib  && ${COPYTREE_SHARE} \* ${APP_HOME}/lib

.if ${PORT_OPTIONS:MAPACHE22}
	${APXS} -i -n caucho -a ${WRKSRC}/modules/c/src/apache2/.libs/mod_caucho.so
.endif
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} "********************************************************************************"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
