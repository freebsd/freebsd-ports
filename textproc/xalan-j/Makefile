# New ports collection makefile for:	xalan-j
# Date created:		21 February 2001
# Whom:			znerd@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	xalan-j
PORTVERSION=	2.3.1
CATEGORIES=	java textproc
MASTER_SITES=	http://xml.apache.org/dist/${PORTNAME}/
DISTNAME=	${PORTNAME}_${PORTVERSION:S/./_/g}
#DISTFILES=	${DISTNAME}-src${EXTRACT_SUFX}
DISTFILES=	${DISTNAME}-bin${EXTRACT_SUFX}

MAINTAINER=	znerd@FreeBSD.org

#BUILD_DEPENDS=	ant:${PORTSDIR}/devel/jakarta-ant
USE_JAVA=	1.2+

#
# We'd love to build Xalan rather than install a binary release, but
# the doc build doesn't seem to work... :(
#
NO_BUILD=	YES

do-configure:
	${SED} 's|%%PREFIX%%|${PREFIX}|g' ${FILESDIR}/xalan.sh >${WRKDIR}/xalan

#do-build:
#	(cd ${WRKSRC} && ant jar)
#.if !defined(NOPORTDOCS)
#	(cd ${WRKSRC} && env CLASSPATH=${WRKSRC}/build/xalan.jar:${CLASSPATH} \
#		ant docs javadocs)
#.endif

do-install:
	${INSTALL_DATA} ${WRKSRC}/bin/xalan.jar ${WRKSRC}/bin/xml-apis.jar \
		${PREFIX}/share/java/classes
	${INSTALL_SCRIPT} ${WRKDIR}/xalan ${PREFIX}/bin
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC}/docs && \
		${TAR} -cf - . | ${TAR} -xf - -C ${DOCSDIR})
.endif

.include <bsd.port.mk>
