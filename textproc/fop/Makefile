# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.17.0
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/fop/
MASTER_SITE_SUBDIR=	recent
DISTNAME=	${PORTNAME:S/fop/Fop/}-${PORTVERSION}

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/jdk${JDKVERSION}/bin/java:${PORTSDIR}/java/jdk \
		${LOCALBASE}/share/java/classes/xerces.jar:${PORTSDIR}/textproc/xerces

WRKSRC=		${WRKDIR}/xml-fop
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

JDKVERSION=	1.1.8
JAVACLASSDIR=	${PREFIX}/share/java/classes
JAVADATADIR=	${PREFIX}/share/java/${PKGNAME}

do-extract:
	${MKDIR} ${WRKSRC}
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DISTFILES} \
		${EXTRACT_AFTER_ARGS} -C ${WRKSRC}

pre-install:
	${MKDIR} ${JAVACLASSDIR} ${JAVADATADIR}
	find ${WRKSRC} \( -name \*.orig -o -name \*~ -o -name CVS \) -exec ${RM} -rf \{} \;

do-install:
	${INSTALL_DATA} ${WRKSRC}/fop.jar ${JAVACLASSDIR}
	${INSTALL_DATA} ${WRKSRC}/lib/w3c.jar ${JAVACLASSDIR}/svg-w3c.jar
	cd ${WRKSRC}; \
		${INSTALL_DATA} LICENSE README STATUS build.xml ${JAVADATADIR}; \
		${INSTALL_SCRIPT} build.sh ${JAVADATADIR}; \
		${CP} -R conf docs hyph javadocs lib src ${JAVADATADIR}

.include <bsd.port.mk>
