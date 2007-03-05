# New ports collection makefile for:    Apache SOAP
# Date created:				Mon Nov 18 11:21:13 EST 2002
# Whom:					Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=	apache-soap
PORTVERSION=	2.3.1
PORTREVISION=	1
CATEGORIES=	net java devel
MASTER_SITES=	${MASTER_SITE_APACHE}
MASTER_SITE_SUBDIR=	ws/soap/version-${PORTVERSION}
DISTNAME=	soap-bin-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	The Apache SOAP implementation in Java

RUN_DEPENDS=	${JAVALIBDIR}/mail.jar:${PORTSDIR}/java/javamail

USE_JAVA=	yes
JAVA_VERSION=	1.2+

WRKSRC=		${WRKDIR}/soap-2_3_1
NO_BUILD=	yes
DATADIR=	${JAVASHAREDIR}/${PORTNAME}
DATAFILES=	LICENSE README webapps

.include <bsd.port.pre.mk>

do-install:
	${INSTALL_DATA} ${WRKSRC}/lib/soap.jar ${JAVAJARDIR}/
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type d -exec ${MKDIR} ${DATADIR}/{} \;
	cd ${WRKSRC} && ${FIND} ${DATAFILES} -type f -exec ${INSTALL_DATA} {} ${DATADIR}/{} \;
.if !defined(NOPORTDOCS)
	cd ${WRKSRC}/docs && ${FIND} . -type d -exec ${MKDIR} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/docs && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${DOCSDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type d -exec ${MKDIR} ${EXAMPLESDIR}/{} \;
	cd ${WRKSRC}/samples && ${FIND} . -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR}/{} \;
.endif

.include <bsd.port.post.mk>
