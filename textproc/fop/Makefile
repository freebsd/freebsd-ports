# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.20.3
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/fop/ \
		http://xml.apache.org/dist/fop/recent/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kiri@FreeBSD.org

RUN_DEPENDS=	${LOCALBASE}/jdk${JDKVERSION}/bin/java:${PORTSDIR}/java/jdk11 \
		${LOCALBASE}/share/java/classes/xerces.jar:${PORTSDIR}/textproc/xerces-j

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

JDKVERSION=	1.1.8
JAVACLASSDIR=	${PREFIX}/share/java/classes
JAVADATADIR=	${PREFIX}/share/java/${PKGNAME}

pre-install:
	${MKDIR} ${JAVACLASSDIR} ${JAVADATADIR}
	find ${WRKSRC} \( -name \*.orig -o -name \*~ -o -name CVS \) -exec ${RM} -rf \{} \;

do-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} build/fop.jar lib/batik.jar lib/stylebook.jar \
			${JAVACLASSDIR}; \
		${INSTALL_DATA} CHANGES LICENSE README ReleaseNotes.html \
			STATUS build.xml buildtools.xml ${JAVADATADIR}; \
		${INSTALL_SCRIPT} build.sh fop.sh ${JAVADATADIR}; \
		${CP} -R conf docs hyph javadocs lib src ${JAVADATADIR}

.include <bsd.port.mk>
