# New ports collection makefile for:	XML for Java
# Version required:	3.0.0-EA3
# Date created:		21 Feb 2000
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xml4J_3_0_0EA3
PKGNAME=	xml4j-3.0.0e3
WRKSRC=		${WRKDIR}/XML4J_3_0_0EA3
CATEGORIES=	textproc
MASTER_SITES=	http://www.alphaworks.ibm.com/tech/xml4j/

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/share/java/classes/jfc-1.1.1/swing.jar:${PORTSDIR}/java/jfc

RESTRICTED=	"License prohibites distribute."
NO_BUILD=	YES

JAVASUBDIR=	jdk1.1.8
DIR=		${PREFIX}/share/java

do-install:
	@${MKDIR} ${DIR}/classes
	@(cd ${WRKSRC} && ${INSTALL_DATA} xml4j.jar xerces.jar xercesSamples.jar ${DIR}/classes)
	@${MKDIR} ${DIR}/xml4j
	@(cd ${WRKSRC} && ${INSTALL_DATA} Readme.html License.html ${DIR}/xml4j)
	@(cd ${WRKSRC} && ${CP} -R data docs samples src ${DIR}/xml4j)

.include <bsd.port.mk>
