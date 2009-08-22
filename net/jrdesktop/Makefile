# New ports collection makefile for:	jrdesktop
# Date created:				May 7 2008
# Whom:					gahr
#
# $FreeBSD$
#

PORTNAME=	jrdesktop
PORTVERSION=	0.2.0030
CATEGORIES=	net java
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
DISTNAME=	${PORTNAME}-${PORTVERSION}.src

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	View and/or control a remote PC

USE_JAVA=	yes
JAVA_VERSION=	1.6+
USE_ANT=	yes
USE_ZIP=	yes

WRKSRC=	${WRKDIR}/${DISTNAME}/${PORTNAME}
TXTFILES=	changes.txt license.txt readme.txt

do-install:
	${INSTALL_DATA} ${WRKSRC}/dist/jrdesktop.jar ${JAVAJARDIR}
	${INSTALL_SCRIPT} ${FILESDIR}/jrdesktop.in ${PREFIX}/bin/jrdesktop

post-install:
	${REINPLACE_CMD} -i "" -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;s|%%JAVA%%|${JAVA}|' \
	    ${PREFIX}/bin/jrdesktop
.if !defined(NOPORTDOCS)
	${INSTALL} -d ${DOCSDIR}
	(cd ${WRKSRC}/dist && ${COPYTREE_SHARE} javadoc ${DOCSDIR})
.for txt in ${TXTFILES}
	${INSTALL_DATA} ${WRKDIR}/${DISTNAME}/${txt} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
