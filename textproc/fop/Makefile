# New ports collection makefile for:	Print formatter driven by XSL formatting
# Date created:		19 December 2000
# Whom:			KIRIYAMA Kazuhiko <kiri@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fop
PORTVERSION=	0.20.5
CATEGORIES=	textproc java
MASTER_SITES=	http://www.apache.org/dist/xml/fop/ \
		http://nagoya.apache.org/mirror/xml/fop/recent/
DISTNAME=	${PORTNAME}-${PORTVERSION}-src

MAINTAINER=	kiri@FreeBSD.org
COMMENT=	Print formatter driven by XSL formatting

WRKSRC=		${WRKDIR}/${DISTNAME:S/-src//}
NO_BUILD=	yes
PLIST_SUB=	PORTVERSION="${PORTVERSION}"

USE_JAVA=	1.2+
NO_BUILD_DEPENDS_JAVA=	YES

pre-install:
	${MKDIR} ${DATADIR} ${DATADIR}/build ${DOCSDIR}
	${FIND} ${WRKSRC} \( -name \*.orig -o -name \*~ -o -name CVS \) -exec ${RM} -rf \{} \;

do-install:
	cd ${WRKSRC}; \
		${INSTALL_DATA} CHANGES LICENSE README ReleaseNotes.html \
			STATUS ${DATADIR}; \
		${INSTALL_SCRIPT} fop.sh ${DATADIR}; \
		${SED} -i "" -e s,%%PREFIX%%,${PREFIX}, ${DATADIR}/fop.sh ;\
		${LN} -sf ${DATADIR}/fop.sh ${PREFIX}/bin/fop; \
		${CP} -R conf src/hyph lib ${DATADIR}; \
		${CP} build/fop.jar ${DATADIR}/build
.if !defined(NOPORTDOCS)
	(cd ${WRKSRC}/build/site && \
		${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
