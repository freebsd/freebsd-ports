# New ports collection makefile for:	jakarta-jmeter
# Date created:		12 August 2002
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmeter
PORTVERSION=	1.8
PORTREVISION=	1
CATEGORIES=	www benchmarks java
MASTER_SITES=	http://jakarta.apache.org/builds/jakarta-jmeter/release/v${PORTVERSION}/ \
		http://www.metaverse.nl/~ernst/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	znerd
PKGNAMEPREFIX=	jakarta-
DISTNAME=	ApacheJMeter_${PORTVERSION}

MAINTAINER=	znerd@FreeBSD.org

USE_JAVA=	1.2+
NO_BUILD=	yes
APP_HOME=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}${PORTVERSION}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
WRKDIR?=	${WRKDIRPREFIX}${.CURDIR}/work
WRKSRC=		${WRKDIR}/${PKGNAMEPREFIX}${PORTNAME}
REPLACE_FILES=	${WRKSRC}/bin/jmeter

post-patch:
	@${ECHO_CMD} -n ">> Removing unneeded files..."
	@${RM} -f `${FIND} ${WRKSRC} -name '*.bat'` `${FIND} ${WRKSRC} -name '*.orig'` `${FIND} ${WRKSRC} -name '*.exe'`
	@${ECHO_CMD} " [ DONE ]"

.for f in ${REPLACE_FILES}
	@${ECHO_CMD} -n ">> Customizing `basename $f`..."
	@${SED} \
	-e "/%%JAVA%%/s//${JAVA:S/\//\\\//g}/g" \
	$f > ${WRKDIR}/`basename $f`
	@${ECHO_CMD} " [ DONE ]"
.endfor

do-install:
	@${ECHO_CMD} -n ">> Creating destination directory..."
	@${MKDIR} ${APP_HOME}
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Copying files to destination directory..."
	@${CP} -R ${WRKSRC}/* ${APP_HOME}
.for f in ${REPLACE_FILES}
	@${CP} ${WRKDIR}/`basename $f` ${APP_HOME}/bin
.endfor
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Fixing permissions..."
	@${CHMOD} 755 `find ${APP_HOME} -type d`
	@${CHMOD} 755 ${APP_HOME}/bin/jmeter
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating symlink ${PREFIX}/bin/jmeter..."
	@${LN} -s ${APP_HOME}/bin/jmeter ${PREFIX}/bin/jmeter
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.mk>
