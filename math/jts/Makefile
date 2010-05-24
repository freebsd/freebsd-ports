# New ports collection makefile for:	jts
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	jts
PORTVERSION=	1.11
CATEGORIES=	math databases
MASTER_SITES=	SF/${PORTNAME}-topo-suite/${PORTNAME}/${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	JTS Topology Suite

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom		\
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit		\
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

VER=		${PORTVERSION:L}
JARFILES=	JTS_Test acme jts-${VER}

do-install:
.for jar in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${jar}.jar	\
		${JAVAJARDIR}/${jar:S|-${VER}||}.jar
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	@cd ${WRKDIR}/doc && ${COPYTREE_SHARE} . ${DOCSDIR}
	@${ECHO_MSG} "===> Documentation installed in ${DOCSDIR}."
.endif

.if defined(MAINTAINER_MODE)
regression-test:	install
	${SED} -e 's|%%JAVAJARDIR%%|${JAVAJARDIR}|;	\
			s|%%JAVALIBDIR%%|${JAVALIBDIR}|;\
			s|%%JAVA%%|${JAVA}|'		\
		${FILESDIR}/testJTS.sh.in > ${WRKSRC}/testJTS.sh
	(cd ${WRKSRC} && ${SH} ./testJTS.sh )
.endif

.include <bsd.port.mk>
