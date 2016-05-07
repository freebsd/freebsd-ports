# Created by: Tomoyuki Sakurai <cherry@trombik.org>
# $FreeBSD$

PORTNAME=	sqlmap
PORTVERSION=	1.0.4.19
CATEGORIES=	security python

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Automatic SQL injection tool

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_TUPLE=	sqlmapproject:sqlmap:aa21550

NO_ARCH=	yes
USES=		python:2.7 shebangfix
SHEBANG_FILES=	*.py
SUB_FILES=	sqlmap.sh
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD} \
		PATH=${PYTHONPREFIX_SITELIBDIR}/sqlmap
PORTDOCS=	*

OPTIONS_DEFINE=	MSF
MSF_DESC=	Enable Metasploit Framework integration

MSF_RUN_DEPENDS=	msfcli:security/metasploit

do-build:
	@${PYTHON_CMD} -m compileall ${WRKSRC}
	@${PYTHON_CMD} -O -m compileall ${WRKSRC}
	${MKDIR} ${WRKDIR}/build/extra/
	${MV} ${WRKSRC}/doc/ ${WRKDIR}/build/
	${MV} ${WRKSRC}/README.md ${WRKDIR}/build/doc/
	${MV} ${WRKSRC}/sqlmap.conf ${WRKDIR}/build/

# remove development files
.for f in .gitattributes .gitignore .travis.yml
	${RM} ${WRKSRC}/${f}
.endfor

# move non-python files out of WRKSRC
.for f in runcmd shellcodeexec
	${MV} ${WRKSRC}/extra/${f} ${WRKDIR}/build/extra/${f}
.endfor
	${MV} ${WRKSRC}/udf ${WRKDIR}/build/extra/

do-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	( cd ${WRKDIR}/build/doc/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR} )

	@${MKDIR} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sqlmap/extra
	( cd ${WRKDIR}/build/extra/ && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR} )
	( cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/sqlmap )

	${INSTALL_DATA} ${WRKDIR}/build/sqlmap.conf ${STAGEDIR}${PREFIX}/etc/sqlmap.conf.sample
	${INSTALL_SCRIPT} ${WRKDIR}/sqlmap.sh ${STAGEDIR}${PREFIX}/bin/sqlmap

.include <bsd.port.mk>
