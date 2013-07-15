# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-appengine
PORTVERSION=	1.8.1
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

LICENSE=	AL2 BSD GPLv2 LGPL21 MIT MPL PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:${PORTSDIR}/security/py-pycrypto

PROJECTHOST=	googleappengine

USE_PYTHON=	2.7
USE_ZIP=	yes
USES=		gettext

OPTIONS_DEFINE=	EXAMPLES MYSQL
OPTIONS_DEFAULT=	MYSQL

.include <bsd.port.options.mk>

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

LN_OPTS=	-s

XARGS_ARGS=	-0
REINPLACE_ARGS=	-e 's,/usr/bin/env python,&${PYTHON_VER},' -i.bak

GAEDATADIR=	google lib new_project_template tools
GAESCRIPTS=	_php_runtime.py _python_runtime.py api_server.py appcfg.py \
		bulkload_client.py bulkloader.py dev_appserver.py \
		download_appstats.py endpointscfg.py gen_protorpc.py \
		google_sql.py old_dev_appserver.py remote_api_shell.py run_tests.py

post-patch:
	@${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

do-build:
.for D in ${GAEDATADIR}
	${PYTHON_CMD} -m compileall ${WRKSRC}/${D} || true
	${PYTHON_CMD} -OO -m compileall ${WRKSRC}/${D} || true
.endfor

do-install:
	${MKDIR} ${DATADIR}
.for D in ${GAEDATADIR}
	cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${DATADIR}
.endfor

.if ${PORT_OPTIONS:MEXAMPLES}
	cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${EXAMPLESDIR}
.endif
.for S in ${GAESCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${S} ${DATADIR}
	${LN} ${LN_OPTS} ${DATADIR}/${S} ${PREFIX}/bin/${S}
.endfor
	${INSTALL_DATA} ${WRKSRC}/VERSION ${DATADIR}

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:${PORTSDIR}/databases/py-MySQLdb
.endif

.include <bsd.port.mk>
