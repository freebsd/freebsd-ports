# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-appengine
DISTVERSION=	1.9.82
PORTREVISION=	1
CATEGORIES=	www devel python
MASTER_SITES=	https://storage.googleapis.com/appengine-sdks/featured/
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

LICENSE=	APACHE20 BSD3CLAUSE GPLv2 LGPL21 MIT MPL11 PSFL
LICENSE_COMB=	multi

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:databases/py-sqlite3@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto@${PY_FLAVOR}

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

USES=		gettext python:2.7 shebangfix zip
NO_ARCH=	yes
NO_BUILD=	yes
SHEBANG_FILES=	${GAESCRIPTS}

OPTIONS_DEFINE=	EXAMPLES MYSQL PHP
OPTIONS_DEFAULT=	MYSQL

PORTDATA=	*
PORTEXAMPLES=	*
PLIST_FILES=	${GAESCRIPTS:C,^| ,bin/&,g}

LN_OPTS=	-sf

GAEDATADIR=	google lib new_project_template tools
GAESCRIPTS=	_php_runtime.py _python_runtime.py api_server.py appcfg.py \
		backends_conversion.py bulkload_client.py bulkloader.py \
		dev_appserver.py download_appstats.py endpointscfg.py \
		gen_protorpc.py php_cli.py remote_api_shell.py \
		run_tests.py wrapper_util.py

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb@${PY_FLAVOR}

PHP_USES=	mysql:server
PHP_VARS=	gaedatadir+=php

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${GAEDATADIR}" ${STAGEDIR}${DATADIR})
	(cd ${STAGEDIR}${PREFIX}/bin && \
	for S in ${GAESCRIPTS}; do \
	${INSTALL_SCRIPT} ${WRKSRC}/$${S} ${STAGEDIR}${DATADIR}; \
	${LN} ${LN_OPTS} ../${DATADIR_REL}/$${S} $${S}; \
	done)
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}

	(cd ${STAGEDIR}${DATADIR} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR} -f ${GAEDATADIR:Nphp} -q)

do-install-EXAMPLES-on:
	cd ${WRKSRC}/demos && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
