# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.15.0
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/fop/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/./_/g}

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=    ${LOCALBASE}/jdk${JDKVERSION}/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/share/java/classes/xerces.jar:${PORTSDIR}/textproc/xerces

WRKSRC=		${WRKDIR}/xml-fop
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

JDKVERSION=	1.1.8
JAVACLASSDIR=	${PREFIX}/share/java/classes
JAVADATADIR=	${PREFIX}/share/java/${PKGNAME}

do-install:
	${MKDIR} ${JAVACLASSDIR} ${JAVADATADIR}
	${INSTALL_DATA} ${WRKSRC}/build/fop.jar ${JAVACLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${JAVACLASSDIR}/svg-w3c.jar
	cd ${WRKSRC}; \
		${INSTALL_DATA} LICENSE README STATUS build.xml ${JAVADATADIR}; \
		${INSTALL_SCRIPT} build.sh ${JAVADATADIR}; \
		${CP} -R docs lib src ${JAVADATADIR}

.include <bsd.port.mk>
