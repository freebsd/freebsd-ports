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
DISTFILES=	${JARFILE} jing.html copying.txt
DIST_SUBDIR=	${PORTNAME}
EXTRACT_ONLY=

MAINTAINER=	fuyuki@mj.0038.net

JAXP?=		crimson # or xalan, saxon

.if ${JAXP} == "xalan"
RUN_DEPENDS+=	${LOCALBASE}/xalan-j2.1.0/bin/${JAXP}.jar:${PORTSDIR}/java/xalan-j
.else
RUN_DEPENDS+=	${LOCALBASE}/share/java/classes/${JAXP}.jar:${PORTSDIR}/textproc/${JAXP}
.endif

USE_JAVA=	1.1+
NO_BUILD_DEPENDS_JAVA=	yes
NO_BUILD=	yes

JARFILE=	${DISTNAME}.jar
JAVALIBDIR=	${PREFIX}/share/java/classes

do-install:
	${MKDIR} ${JAVALIBDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/${JARFILE} ${JAVALIBDIR}

post-install:
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.html ${DOCSDIR}
	${INSTALL_DATA} ${DISTDIR}/${DIST_SUBDIR}/*.txt ${DOCSDIR}

.include <bsd.port.mk>
