# New ports collection makefile for:	jakarta-jmeter
# Date created:		12 August 2002
# Whom:			Ernst de Haan <znerd@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	jmeter
PORTVERSION=	1.9.1
PORTREVISION=	1
CATEGORIES=	www benchmarks java
MASTER_SITES=	${MASTER_SITE_APACHE_JAKARTA}
MASTER_SITE_SUBDIR=	jmeter/binaries
PKGNAMEPREFIX=	jakarta-
DISTNAME=	${PKGNAMEPREFIX}${PORTNAME}-${PORTVERSION}
EXTRACT_SUFX=	.tgz

MAINTAINER=	znerd@FreeBSD.org
COMMENT=	Functional behaviour load and performance test application

USE_JAVA=	1.3+
NO_BUILD=	yes
APP_HOME?=	${PREFIX}/${PKGNAMEPREFIX}${PORTNAME}
PLIST_SUB+=	T=${APP_HOME:S/^${PREFIX}\///}
REPLACE_FILES=	${FILESDIR}/jmeter

.include <bsd.port.pre.mk>

post-patch:
	@${ECHO_CMD} -n ">> Removing unneeded files..."
	@${FIND} ${WRKSRC} -type f \( -name \*.bat -o -name \*.orig -o -name \*.exe -o -name \*.bak \) -delete
	@${ECHO_CMD} " [ DONE ]"

.for f in ${REPLACE_FILES}
	@${ECHO_CMD} -n ">> Customizing `basename $f`..."
	@${SED} \
	-e "/%%JAVA%%/s//${JAVA:S/\//\\\//g}/g" \
	-e "/%%APP_HOME%%/s//${APP_HOME:S/\//\\\//g}/g" \
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
	@${FIND} ${APP_HOME} -print0 -type d | ${XARGS} -0 ${CHMOD} 755
	@${CHMOD} 755 ${APP_HOME}/bin/jmeter
	@${ECHO_CMD} " [ DONE ]"

	@${ECHO_CMD} -n ">> Creating symlink ${PREFIX}/bin/jmeter..."
	@${LN} -sf ${APP_HOME}/bin/jmeter ${PREFIX}/bin/jmeter
	@${ECHO_CMD} " [ DONE ]"

.include <bsd.port.post.mk>
