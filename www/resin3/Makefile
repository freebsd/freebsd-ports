# New ports collection makefile for:   resin3
# Whom:                                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                        2003-09-29 14:17:14
#
# $FreeBSD$
#

PORTNAME=		resin
PORTVERSION=		3.0.19
CATEGORIES=		www java
MASTER_SITES=		http://www.caucho.com/download/

MAINTAINER=		jb.quenot@caraldi.com
COMMENT=		Resin, a Java-based Application Server, 3.x branch

USE_JAVA=		yes
JAVA_VERSION=		1.2+
HAS_CONFIGURE=		yes
USE_PYTHON=		yes
USE_OPENSSL=		yes
USE_AUTOTOOLS=		libtool:15

# Customizable settings
RUNASUSER?=		www
RUNASUID?=		80
GROUP?=			${RUNASUSER}
GID?=			${RUNASUID}
PORT?=			8080
# Do not use PKGNAMESUFFIX here because version info is already in PORTVERSION
# If we used PKGNAMESUFFIX, the package name would be resin2-2.1.11
APP_NAME_SUFFIX=	${PORTVERSION:C/\..*$//}
APP_NAME?=		${PORTNAME}${APP_NAME_SUFFIX}
LATEST_LINK=		${APP_NAME}
APP_HOME?=		${PREFIX}/${APP_NAME}
WITH_APACHE?=		NO
WITH_APACHE2?=		NO
PID_FILE?=		${APP_HOME}/${APP_NAME}.pid
LOG_FILE?=		${APP_HOME}/${APP_NAME}.log

# Other settings
APXS?=			${LOCALBASE}/sbin/apxs
PKGINSTALL=		${WRKDIR}/pkg-install
PKGDEINSTALL=		${WRKDIR}/pkg-deinstall
PKGMESSAGE=		${WRKDIR}/pkg-message
REINPLACE_FILES=	${WRKSRC}/modules/c/src/apache1/Makefile.in \
			${WRKSRC}/modules/c/src/apache2/Makefile.in
REPLACE_FILES=		${FILESDIR}/pkg-install \
			${FILESDIR}/pkg-deinstall \
			${FILESDIR}/install.sh \
			${FILESDIR}/pkg-message.in \
			${WRKSRC}/conf/resin.conf \
			${FILESDIR}/resinctl \
			${FILESDIR}/resin.sh.in
COPYDIRS=		lib libexec webapps

.include <bsd.port.pre.mk>

# Pass JAVA_HOME as determined by bsd.java.mk
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME} \
			--with-openssl-lib=${OPENSSLLIB} \
			--with-openssl-include=${OPENSSLINC}
LDFLAGS+=		-L${OPENSSLLIB} -lcrypto -lssl
# We need to link with cc instead of ld for the FreeBSD specific options used
# by threading libraries
CONFIGURE_ENV=		LD=${CC} PTHREAD_LIBS=${PTHREAD_LIBS} LDFLAGS="${LDFLAGS}" LIBTOOL=${LIBTOOL}

# Install the Apache plugin if needed
.if defined(WITH_APACHE) && (${WITH_APACHE} == yes || ${WITH_APACHE} == YES)
#
# Apache 1.3
#
BUILD_DEPENDS+=		${APXS}:${PORTSDIR}/www/apache13
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=		MOD_DIR=libexec/apache
# Allow apxs invocations
PLIST_SUB+=		APACHE=""
.elif defined(WITH_APACHE2) && (${WITH_APACHE2} == yes || ${WITH_APACHE2} == YES)
#
# Apache 2
#
BUILD_DEPENDS+=		${APXS}:${PORTSDIR}/www/apache20
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=		MOD_DIR=libexec/apache2
# Allow apxs invocations
PLIST_SUB+=		APACHE=""
.else
PLIST_SUB+=		MOD_DIR="@comment "
# Prevent apxs invocations
PLIST_SUB+=		APACHE="@comment "
.endif

PLIST_SUB+=		APP_NAME=${APP_NAME}
PLIST_SUB+=		APXS=${APXS}

SUBSTITUTIONS=		-e "s|%%APP_HOME%%|${APP_HOME}|g" \
			-e "s|%%APP_NAME%%|${APP_NAME}|g" \
			-e "s|%%APXS%%|${APXS}|g" \
			-e "s|%%COPYDIRS%%|${COPYDIRS}|g" \
			-e "s|%%FILESDIR%%|${FILESDIR}|g" \
			-e "s|%%GID%%|${GID}|g" \
			-e "s|%%GROUP%%|${GROUP}|g" \
			-e "s|%%JAVA%%|${JAVA}|g" \
			-e "s|%%JAVA_HOME%%|${JAVA_HOME}|g" \
			-e "s|%%LOG_FILE%%|${LOG_FILE}|g" \
			-e "s|%%PID_FILE%%|${PID_FILE}|g" \
			-e "s|%%PORT%%|${PORT}|g" \
			-e "s|%%PORTNAME%%|${PORTNAME}|g" \
			-e "s|%%PREFIX%%|${PREFIX}|g" \
			-e "s|%%PYTHON_CMD%%|${PYTHON_CMD}|g" \
			-e "s|%%RUNASUID%%|${RUNASUID}|g" \
			-e "s|%%RUNASUSER%%|${RUNASUSER}|g" \
			-e "s|%%WRKDIR%%|${WRKDIR}|g" \
			-e "s|%%WRKSRC%%|${WRKSRC}|g"

post-patch:
	@${REINPLACE_CMD} ${SUBSTITUTIONS} ${REINPLACE_FILES}
	@for FILE in ${REPLACE_FILES} ; do \
	    ${SED} ${SUBSTITUTIONS} $${FILE} > ${WRKDIR}/`basename $${FILE}` ; \
	    done
	@${FMT} -w 80 < ${WRKDIR}/pkg-message.in > ${PKGMESSAGE}
.if (defined(WITH_APACHE2) && (${WITH_APACHE2} == yes || ${WITH_APACHE2} == YES) || \
defined(WITH_APACHE) && (${WITH_APACHE} == yes || ${WITH_APACHE} == YES))
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${ECHO_CMD} The Resin Apache module mod_caucho has been activated \
	    in the Apache configuration file, where you should also \
	    add a line to specify the location of the Resin configuration \
	    server, for example: | ${FMT} -w 80 >> ${PKGMESSAGE}
	@${ECHO_CMD} >> ${PKGMESSAGE}
	@${ECHO_CMD} "<IfModule mod_caucho.c>" >> ${PKGMESSAGE}
	@${ECHO_CMD} "    ResinConfigServer localhost 6802" >> ${PKGMESSAGE}
	@${ECHO_CMD} "</IfModule>" >> ${PKGMESSAGE}
.endif

post-build:
	cd ${WRKSRC}/modules/c/src/resin_os && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_ARGS} install

# Resin does not handle installation, so proceed now
do-install:
	@${SETENV} RUNASUSER=${RUNASUSER} GROUP=${GROUP} ${SH} ${WRKDIR}/install.sh
.if (defined(WITH_APACHE2) && (${WITH_APACHE2} == yes || ${WITH_APACHE2} == YES))
	${APXS} -i -n caucho -a ${WRKSRC}/modules/c/src/apache2/.libs/mod_caucho.so
.endif
.if (defined(WITH_APACHE) && (${WITH_APACHE} == yes || ${WITH_APACHE} == YES))
	${APXS} -i -n caucho -a ${WRKSRC}/modules/c/src/apache1/.libs/mod_caucho.so
.endif
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
	@${ECHO_MSG}
	@${ECHO_MSG} "********************************************************************************"
	@${CAT} ${PKGMESSAGE}
	@${ECHO_MSG} "********************************************************************************"
	@${ECHO_MSG}

.include <bsd.port.post.mk>
