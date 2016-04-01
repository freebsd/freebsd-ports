# Created by: Pedro F. Giffuni <giffunip@asme.org>
# $FreeBSD$

PORTNAME=	jama
PORTVERSION=	1.2.5
CATEGORIES=	math devel
MASTER_SITES=	http://math.nist.gov/tnt/
DISTNAME=	${PORTNAME}${PORTVERSION:S/.//g}
DIST_SUBDIR=	tnt
EXTRACT_ONLY=	# empty
DISTFILES=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	erik@bz.bzflag.bz
COMMENT=	Java-like Matrix C++ Templates

BUILD_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:devel/tnt
RUN_DEPENDS=	${LOCALBASE}/include/tnt/tnt.h:devel/tnt

USES=		zip
NO_BUILD=	yes

OPTIONS_DEFINE=	DOCS

DOCS_DISTFILES=	jama102doc.zip

do-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/include/tnt
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/${DISTNAME}${EXTRACT_SUFX} \
		-d ${STAGEDIR}${PREFIX}/include/tnt
	${MKDIR} ${WRKDIR}/doc ${STAGEDIR}${DOCSDIR}

do-install-DOCS-on:
	${EXTRACT_CMD} ${EXTRACT_BEFORE_ARGS} ${DISTDIR}/${DIST_SUBDIR}/jama102doc.zip \
		-d ${WRKDIR}/doc
	(cd ${WRKDIR}/doc/doxygen && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
