# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	sqlmap
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	security python
MASTER_SITES=	https://github.com/sqlmapproject/sqlmap/downloads/ \
		SF

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Automatic SQL injection tool

LICENSE=	GPLv2

USE_PYTHON=	2
WRKSRC=		${WRKDIR}/${PORTNAME}
SUB_FILES=	${PORTNAME}.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}

OPTIONS_DEFINE=	MSF
MSF_DESC=	Enable Metasploit Framework integration

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if  ${PORT_OPTIONS:MMSF}
RUN_DEPENDS+=	${LOCALBASE}/bin/msfcli:${PORTSDIR}/security/metasploit
.endif

post-patch:
	(cd ${WRKSRC} && ${RM} -rf `${FIND} . -type d -name .svn`)
	@${RM} -f ${WRKSRC}/lib/core/settings.py.orig
	@${GREP} -lr '/usr/bin/env python' ${WRKSRC} | \
		${XARGS} ${REINPLACE_CMD} -i "" \
		-e "s!/usr/bin/env python!${PYTHON_CMD}!"

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	${MKDIR} ${WRKDIR}/build/extra/
	${MV} ${WRKSRC}/doc/ ${WRKDIR}/build/
.for F in msfauxmod runcmd udfhack
	${MV} ${WRKSRC}/extra/${F} ${WRKDIR}/build/extra/${F}
.endfor

do-install:
.if  ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
.for F in AUTHORS ChangeLog README.html README.pdf THANKS
	${INSTALL_DATA} ${WRKDIR}/build/doc/${F} ${DOCSDIR}/
.endfor
.endif

	${MKDIR} ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME}/extra
	( cd ${WRKDIR}/build/extra/ && ${COPYTREE_SHARE} . ${DATADIR} )
	( cd ${WRKSRC} && ${COPYTREE_SHARE} . ${PYTHONPREFIX_SITELIBDIR}/${PORTNAME} )

	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf-dist
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME}.sh ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
