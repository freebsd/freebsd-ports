# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.20.4
CATEGORIES=	textproc java
MASTER_SITES=	http://xml.apache.org/dist/fop/ \
		http://xml.apache.org/dist/fop/recent/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kiri@FreeBSD.org

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

USE_JAVA=	1.2+
NO_BUILD_DEPENDS_JAVA=	YES

JAVA_LIBDIR=	${PREFIX}/share/java/classes

pre-install:
	${MKDIR} ${JAVA_LIBDIR} ${DATADIR} ${DOCSDIR}
	find ${WRKSRC} \( -name \*.orig -o -name \*~ -o -name CVS \) -exec ${RM} -rf \{} \;

do-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} build/fop.jar ${JAVA_LIBDIR}; \
		${INSTALL_DATA} CHANGES LICENSE README ReleaseNotes.html \
			STATUS build.xml buildtools.xml ${DATADIR}; \
		${INSTALL_SCRIPT} build.sh fop.sh ${DATADIR}; \
		${LN} -sf ${DATADIR}/fop.sh ${PREFIX}/bin/fop; \
		${CP} -R build conf hyph lib ${DATADIR}
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/docs && \
		${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
