# New ports collection makefile for:	XML for Java
# Version required:	2.0.15
# Date created:		16 May 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

DISTNAME=	xml4j_2_0_15
PKGNAME=	xml4j-2.0.15
CATEGORIES=	textproc
MASTER_SITES=	http://www.alphaworks.ibm.com/tech/xml4j/

MAINTAINER=	kuriyama@FreeBSD.org

RUN_DEPENDS=	${PREFIX}/${JFCSUBDIR}/swing.jar:${PORTSDIR}/java/jfc

RESTRICTED=	"License prohibites distribute."
NO_BUILD=	YES
PLIST_SUB=	JAVASUBDIR=${JAVASUBDIR}

JAVASUBDIR=	jdk1.1.8
JFCSUBDIR=	swing-1.1
DIR=		${PREFIX}/share/java

do-install:
	@${MKDIR} ${DIR}/classes
	@(cd ${WRKSRC} && ${INSTALL_DATA} xml4j.jar xml4jSamples.jar ${DIR}/classes)
	@${MKDIR} ${DIR}/xml4j
	@(cd ${WRKSRC} && ${INSTALL_DATA} Readme.html license.html w3c_copyright_software.html ${DIR}/xml4j)
	@(cd ${WRKSRC} && ${CP} -R TXapiDocs apiDocs build data docs samples ${DIR}/xml4j)

.include <bsd.port.mk>
