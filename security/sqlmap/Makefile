# New ports collection makefile for:	sqlmap
# Date created:		2008-05-21
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	sqlmap
PORTVERSION=	0.7
CATEGORIES=	security python
MASTER_SITES=	SF

MAINTAINER=	niels@FreeBSD.org
COMMENT=	An automatic SQL injection tool

USE_PYTHON=	yes
SQLMAP_DOCS=	AUTHORS COPYING ChangeLog README.html README.pdf THANKS
SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

post-patch:
	@${GREP} -lr '/usr/bin/env python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
		-e "s!/usr/bin/env python!${PYTHON_CMD}!"

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}
	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}
.	for F in lib shell plugins txt udf xml
		${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/${F}
		( cd ${WRKSRC}/${F} && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/${F} )
.	endfor
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf-dist
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.py ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for F in ${SQLMAP_DOCS}
	${INSTALL_DATA} ${WRKSRC}/doc/${F} ${DOCSDIR}/
.endfor
.endif

.include <bsd.port.mk>
