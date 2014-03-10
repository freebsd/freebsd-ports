# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	jama
PORTVERSION=	1.2.5
CATEGORIES=	math devel
MASTER_SITES=	http://math.nist.gov/tnt/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
.ifndef NOPORTDOCS
DISTFILES=${DISTNAME}${EXTRACT_SUFX} jama102doc.zip
.endif
DIST_SUBDIR=	tnt
EXTRACT_ONLY=

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Java-like Matrix C++ Templates

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:${PORTSDIR}/devel/tnt \
		unzip:${PORTSDIR}/archivers/unzip
RUN_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:${PORTSDIR}/devel/tnt

USES=		zip:infozip
NO_BUILD=	yes

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tnt
	${EXTRACT_CMD} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME} \
		-d ${STAGEDIR}${PREFIX}/include/tnt
	${MKDIR} ${WRKDIR}/doc ${STAGEDIR}${DOCSDIR}
	${EXTRACT_CMD} -o ${DISTDIR}/${DIST_SUBDIR}/jama102doc \
		-d ${WRKDIR}/doc
	(cd ${WRKDIR}/doc/doxygen && ${COPYTREE_SHARE} \* ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
