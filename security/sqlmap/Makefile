# New ports collection makefile for:	sqlmap
# Date created:		2008-05-21
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	sqlmap
PORTVERSION=	0.5
CATEGORIES=	security python
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An automatic SQL injection tool

USE_PYTHON=	yes
NO_BUILD=	yes
# XXX report to upstream
WRKSRC=		${WRKDIR}/${PORTNAME}
SQLMAP_TXT_FILES=	fuzz_vectors.txt user-agents.txt
SQLMAP_DOC_FILES=	AUTHORS ChangeLog README.html THANKS TODO

post-patch:
# XXX report to upstream
	${REINPLACE_CMD} -e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|g' \
		-e 's|%%PORTNAME%%|${PORTNAME}|g' ${WRKSRC}/sqlmap.py
	${REINPLACE_CMD} -e 's|from lib\.|from ${PORTNAME}.|' \
		-e 's|from plugins\.|from ${PORTNAME}.plugins.|' ${WRKSRC}/lib/*
	${REINPLACE_CMD} -e 's|from lib\.|from ${PORTNAME}.|' \
		-e 's|from plugins\.|from ${PORTNAME}.plugins.|' ${WRKSRC}/plugins/*

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/sqlmap.py ${PREFIX}/bin/sqlmap
	${RM} -rf ${WRKSRC}/lib/.svn
	${RM} -rf ${WRKSRC}/lib/*.bak
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/sqlmap
	( cd ${WRKSRC}/lib && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/sqlmap )
	${RM} -rf ${WRKSRC}/plugins/.svn
	${RM} -rf ${WRKSRC}/plugins/*.bak
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR:}/sqlmap/plugins
	( cd ${WRKSRC}/plugins && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/sqlmap/plugins )
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}/txt
.for F in ${SQLMAP_TXT_FILES}
	${INSTALL_DATA} ${WRKSRC}/txt/${F} ${DATADIR}/txt/
.endfor
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${SQLMAP_DOC_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${F} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
