# New ports collection makefile for:    Apache SOAP
# Date created:				Mon Nov 18 11:21:13 EST 2002
# Whom:					Brian Skrab <brian@quynh-and-brian.org>
#
# $FreeBSD$
#

PORTNAME=	apache-soap
PORTVERSION=	2.3.1
CATEGORIES=	net java devel
MASTER_SITES=	http://apache.inspire.net.nz/ws/soap/version-2.3.1/ \
		http://cottage.quynh-and-brian.org/freebsd/ports/distfiles/
DISTNAME=	soap-bin-${PORTVERSION}

MAINTAINER=	brian@quynh-and-brian.org
COMMENT=	The Apache SOAP implementation in Java

RUN_DEPENDS=	${LOCALBASE}/share/java/classes/mail.jar:${PORTSDIR}/java/javamail

USE_JAVA=	1.2+

WRKSRC=		${WRKDIR}/soap-2_3_1
NO_BUILD=	yes
TARGET_DIR=	${PREFIX}/share/java/${PKGNAME}
PLIST_SUB+=	T=${TARGET_DIR:S/^${PREFIX}\///}

.include <bsd.port.pre.mk>

do-install:
	${MKDIR} ${PREFIX}/share/java/classes
	${MKDIR} ${TARGET_DIR}
	${CP} -R ${WRKSRC}/* ${TARGET_DIR}
	${LN} -sf ${TARGET_DIR}/lib/soap.jar ${PREFIX}/share/java/classes/soap.jar
	${LN} -sf ${TARGET_DIR}/docs ${PREFIX}/share/doc/${PORTNAME}

.include <bsd.port.post.mk>
