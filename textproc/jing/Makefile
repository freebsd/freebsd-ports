# New ports collection makefile for:   jing
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jing
PORTVERSION=	2002.07.24
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/relaxng/
DISTNAME=	${PORTNAME}-bin

MAINTAINER=	fuyuki@hadaly.org

JAXP?=		crimson # or xalan, saxon

.if ${JAXP} == "xalan"
RUN_DEPENDS+=	${LOCALBASE}/xalan-j2.1.0/bin/${JAXP}.jar:${PORTSDIR}/java/xalan-j
.else
RUN_DEPENDS+=	${LOCALBASE}/share/java/classes/${JAXP}.jar:${PORTSDIR}/textproc/${JAXP}
.endif

USE_ZIP=	yes
USE_JAVA=	1.2+
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

NO_BUILD_DEPENDS_JAVA=	yes
JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${WRKSRC}/*.jar ${JAVALIBDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/*.html ${WRKSRC}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
