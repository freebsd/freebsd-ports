# New ports collection makefile for:   jing
# Date created:                3 February 2002
# Whom:                        Kimura Fuyuki <fuyuki@mj.0038.net>
#
# $FreeBSD$
#

PORTNAME=	jing
PORTVERSION=	2002.02.13
CATEGORIES=	textproc
MASTER_SITES=	http://www.thaiopensource.com/relaxng/
DISTNAME=	${PORTNAME}
DISTFILES=	${JAR} jing.html copying.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	fuyuki@mj.0038.net

JAXP?=		crimson # or xalan, saxon

RUN_DEPENDS=	javavm:${PORTSDIR}/java/javavmwrapper

.if ${JAXP} == "xalan"
RUN_DEPENDS+=	${LOCALBASE}/xalan-j2.1.0/bin/${JAXP}.jar:${PORTSDIR}/java/xalan-j
.else
RUN_DEPENDS+=	${LOCALBASE}/share/java/classes/${JAXP}.jar:${PORTSDIR}/textproc/${JAXP}
.endif

NO_BUILD=	yes

JAR=		${DISTNAME}.jar
JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${JAR} ${JAVALIBDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
