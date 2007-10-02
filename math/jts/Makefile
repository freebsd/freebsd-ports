# New ports collection makefile for:	jts
# Date created:		22 May 2005
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	jts
PORTVERSION=	1.8.0
CATEGORIES=	math databases
MASTER_SITES=	http://www.vividsolutions.com/Jts/bin/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	JTS Topology Suite

RUN_DEPENDS=	${JAVALIBDIR}/jdom.jar:${PORTSDIR}/java/jdom		\
		${JAVALIBDIR}/junit.jar:${PORTSDIR}/java/junit		\
		${JAVALIBDIR}/xml-apis.jar:${PORTSDIR}/textproc/xerces-j

USE_ZIP=	yes
NO_BUILD=	yes
USE_JAVA=	yes
NO_WRKSUBDIR=	yes

VER=		${PORTVERSION:R}
# Note: ATM JTS requires a deprecated jdom - to be checked when upgrading!
JARFILES=	JTS_Test acme jts-${VER} jtsio-${VER} jdom-old

DOCS=		"JTS Developer Guide.pdf" "JTS Technical Specs.pdf"	\
		"JTS TestBuilder & TestRunner User Guide.pdf"		\
		"JTS Version History.html"
PORTDOCS0=	${DOCS:S| |_|g}
PORTDOCS=	${PORTDOCS0:S|&|and|g}

PLIST_FILES=	${JARFILES:S|^|%%JAVAJARDIR%%/|:S|$|.jar|:S|-${VER}||}

post-extract:
	${MV} ${WRKSRC}/lib/jdom.jar ${WRKSRC}/lib/jdom-old.jar
.for pdf in ${PORTDOCS0}
	${MV} ${WRKSRC}/doc/${pdf:S|_| |g} ${WRKSRC}/doc/${pdf}
.endfor

do-install:
.for jar in ${JARFILES}
	${INSTALL_DATA} ${WRKSRC}/lib/${jar}.jar	\
		${JAVAJARDIR}/${jar:S|-${VER}||}.jar
.endfor
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS0:S|^|${WRKSRC}/doc/|} ${DOCSDIR}
	${MV} "${DOCSDIR}/JTS_TestBuilder_&_TestRunner_User_Guide.pdf"	\
		"${DOCSDIR}/JTS_TestBuilder_and_TestRunner_User_Guide.pdf"
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
