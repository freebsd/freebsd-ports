# New ports collection makefile for:   xp
# Date created:        21 September 1999
# Whom:                mike
#
# $FreeBSD$
#

PORTNAME=	xp
PORTVERSION=	0.5
CATEGORIES=	textproc java
MASTER_SITES=	ftp://ftp.jclark.com/pub/xml/
DISTNAME=	${PORTNAME}

MAINTAINER=	mike@vee.net

RUN_DEPENDS=	${LOCALBASE}/jdk1.1.8/bin/java:${PORTSDIR}/java/jdk11

PLIST_SUB+=	XP_VERSION=${PORTVERSION}

NO_WORKSUBDIR=	yes
NO_BUILD=	yes
USE_ZIP=	yes

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/share/java/classes ${PREFIX}/share/java/${PKGNAME}
	${INSTALL_DATA} \
		${WRKDIR}/xp.jar \
		${PREFIX}/share/java/classes/${PKGNAME}.jar
	cd ${WRKDIR}; \
		${CP} -R docs ${PREFIX}/share/java/${PKGNAME}; \
		${CP} -R com ${PREFIX}/share/java/${PKGNAME}

.include <bsd.port.post.mk>
