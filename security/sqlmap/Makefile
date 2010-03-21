# New ports collection makefile for:	sqlmap
# Date created:		2008-05-21
# Whom:			Tomoyuki Sakurai <cherry@trombik.org>
#
# $FreeBSD$
#

PORTNAME=	sqlmap
PORTVERSION=	0.8
CATEGORIES=	security python
MASTER_SITES=	SF

MAINTAINER=	niels@FreeBSD.org
COMMENT=	An automatic SQL injection tool

USE_PYTHON=	2.5+
USE_BZIP2=	YES
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

OPTIONS=	MSF "Enable Metasploit Framework integration" off \
		PSY "Enable Psyco optimizer (recommended)" on

.include <bsd.port.options.mk>

.if defined(WITH_MSF)
RUN_DEPENDS+=	${LOCALBASE}/bin/msfcli:${PORTSDIR}/security/metasploit
.endif
.if defined(WITH_PSY)
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/psyco/core.py:${PORTSDIR}/devel/py-psyco
.endif

post-patch:
	(cd ${WRKSRC} && ${RM} -rf `${FIND} . -type d -name .svn`)
	@${GREP} -lr '/usr/bin/env python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
		-e "s!/usr/bin/env python!${PYTHON_CMD}!"

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	${MKDIR} ${WRKDIR}/build/extra/
	${MV} ${WRKSRC}/doc/ ${WRKDIR}/build/
.	for F in msfauxmod runcmd udfhack
		${MV} ${WRKSRC}/extra/${F} ${WRKDIR}/build/extra/${F}
.	endfor

do-install:
.	if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.	for F in AUTHORS COPYING ChangeLog README.html README.pdf THANKS
		${INSTALL_DATA} ${WRKDIR}/build/doc/${F} ${DOCSDIR}/
.	endfor
.endif

	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/extra
	( cd ${WRKDIR}/build/extra/ && ${COPYTREE_SHARE} . ${DATADIR} )
	( cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} )

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf-dist
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
