# New ports collection makefile for:	jrdesktop
# Date created:				May 7 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	jrdesktop
PORTVERSION=	0.2.0020
PORTREVISION=	1
CATEGORIES=	net java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	View and/or control a remote PC

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${PORTNAME}

PLIST_FILES=	%%JAVAJARDIR%%/jrdesktop.jar \
		bin/jrdesktop

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jrdesktop.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/jrdesktop.in ${PREFIX}/bin/jrdesktop

post-install:
	${REINPLACE_CMD} -i "" -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;s|%%JAVA%%|${JAVA}|' \
	    ${PREFIX}/bin/jrdesktop

.include <bsd.port.mk>
