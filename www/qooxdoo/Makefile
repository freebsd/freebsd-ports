# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	qooxdoo
PORTVERSION=	5.0.1
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}-current/${PORTVERSION}/
DISTNAME=	${PORTNAME}-${PORTVERSION}-sdk

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Comprehensive and innovative Ajax application framework

LICENSE=	LGPL3 EPL
LICENSE_COMB=	dual

USES=		zip python:2.7

OPTIONS_DEFINE=	DOCS EXAMPLES

PORTDOCS=	*
PORTEXAMPLES=	*

post-patch:
	${FIND} ${WRKSRC} -type f -name '*.py' -print0 | ${XARGS} -0 \
		${REINPLACE_CMD} -e 's|/usr/bin/env python|&${PYTHON_VER}|'
	${FIND} ${WRKSRC} -type f -and \( -name '*.orig' -or -name '*.bak' \) -delete

do-build:
	${PYTHON_CMD} -m compileall -f ${WRKSRC}/tool
	${PYTHON_CMD} -O -m compileall -f ${WRKSRC}/tool

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} \
		"create-application.py component framework tool version.txt" \
		${STAGEDIR}${DATADIR})
	(cd ${WRKSRC}/documentation/manual && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})
	(cd ${WRKSRC}/application && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

# build plist
# make the python files executable
	${ECHO_CMD} '@mode ${BINMODE}' >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR} -type f -name '*.py' | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

	${ECHO_CMD} '@mode 644' >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR} -type f \! -name '*.py' | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}

	${ECHO_CMD} '@mode' >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${DATADIR}/* -type d | ${SORT} -r | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/|@dir |' >> ${TMPPLIST}
	${FIND} ${STAGEDIR}${EXAMPLESDIR}/* -type d | ${SORT} -r | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/|@dir |' >> ${TMPPLIST}
	${ECHO_CMD} '@dir ${DATADIR_REL}' >> ${TMPPLIST}

.include <bsd.port.mk>
