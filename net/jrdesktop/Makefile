# New ports collection makefile for:	jrdesktop
# Date created:				May 7 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	jrdesktop
PORTVERSION=	0.2.0012
CATEGORIES=	net java
MASTER_SITES=	SF
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	View and/or control a remote PC

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/src

PLIST_FILES=	%%JAVAJARDIR%%/jrdesktop.jar \
		bin/jrdesktop-server \
		bin/jrdesktop-viewer

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jrdesktop.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/jrdesktop-server.in ${PREFIX}/bin/jrdesktop-server
	${INSTALL_SCRIPT} ${FILESDIR}/jrdesktop-viewer.in ${PREFIX}/bin/jrdesktop-viewer

post-install:
	${REINPLACE_CMD} -i "" -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;s|%%JAVA%%|${JAVA}|' \
	    ${PREFIX}/bin/jrdesktop-server ${PREFIX}/bin/jrdesktop-viewer

.include <bsd.port.mk>
