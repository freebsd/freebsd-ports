# New ports collection makefile for:   resin2
# Whom:                                Jean-Baptiste Quenot <jb.quenot@caraldi.com>
# Date Created:                        2002-07-15 15:00:43
#
# $FreeBSD$
#

PORTNAME=	resin
PORTVERSION=	2.1.11
CATEGORIES=	www java
MASTER_SITES=	http://www.caucho.com/download/

MAINTAINER=	jb.quenot@caraldi.com
COMMENT=	Resin, a Java-based Application Server, 2.x branch

USE_JAVA=	1.2+
HAS_CONFIGURE=	yes
USE_PERL5=	yes

# Customizable settings
RUNASUSER?=	www
RUNASUID?=	80
GROUP?=	${RUNASUSER}
GID?=	${RUNASUID}
PORT?=	8080
APP_HOME?=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
WITH_APACHE?=	NO
WITH_APACHE2?=	NO

# Other settings
APXS?=	${LOCALBASE}/sbin/apxs
MOD_DIR?=	`${APXS} -q LIBEXECDIR`

# Pass JAVA_HOME as determined by bsd.java.mk
CONFIGURE_ARGS+=	--with-java-home=${JAVA_HOME}

# Install the Apache plugin if needed
.if defined(WITH_APACHE) && ($(WITH_APACHE) == yes || $(WITH_APACHE) == YES)
#
# Apache 1.3
#
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/www/apache13
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=	MOD_DIR=libexec/apache
.elif defined(WITH_APACHE2) && ($(WITH_APACHE2) == yes || $(WITH_APACHE2) == YES)
#
# Apache 2
#
BUILD_DEPENDS+=	${APXS}:${PORTSDIR}/www/apache2
CONFIGURE_ARGS+=	--with-apxs=${APXS}
PLIST_SUB+=	MOD_DIR=libexec/apache2
.else
PLIST_SUB+=	MOD_DIR="@comment "
.endif

.include <bsd.port.pre.mk>

# Resin does not handle installation, so proceed now
pre-install:
	$(SED) -i -e "s|%%PREFIX%%|$(PREFIX)|g" $(WRKSRC)/src/c/plugin/apache/install.sh
	$(SED) -i -e "s|%%PREFIX%%|$(PREFIX)|g" $(WRKSRC)/src/c/plugin/apache2/install.sh

# Do not change the PID file location unless you also change it in pkg-deinstall script
PID_FILE=	/var/run/resin.pid

post-install:
	${TOUCH} ${PID_FILE}
	${CHOWN} ${RUNASUID}:${GID} ${PID_FILE}
	${MKDIR} ${APP_HOME}
	@PREFIX=${PREFIX} \
	PKGNAMEPREFIX=${PKGNAMEPREFIX} \
	PORTNAME=${PORTNAME} \
	WRKSRC=${WRKSRC} \
	RUNASUSER=${RUNASUSER} \
	RUNASUID=${RUNASUID} \
	GROUP=${GROUP} \
	GID=${GID} \
	PORT=${PORT} \
	APP_HOME=${APP_HOME} \
	JAVA_HOME=${JAVA_HOME} \
	${SH} pkg-install ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>

# ex:ts=18
