# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-appengine
PORTVERSION=	1.9.51
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	https://storage.googleapis.com/appengine-sdks/featured/
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

LICENSE=	APACHE20 BSD3CLAUSE GPLv2 LGPL21 MIT MPL11 PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:security/py-pycrypto@${PY_FLAVOR}

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES MYSQL PHP
OPTIONS_DEFAULT=	MYSQL

PORTDATA=	*
PORTEXAMPLES=	*
PLIST_FILES=	${GAESCRIPTS:C,^| ,bin/&,g}

USES=		gettext python:2 shebangfix zip

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

LN_OPTS=	-sf

GAEDATADIR=	google lib new_project_template tools
GAESCRIPTS=	_php_runtime.py _python_runtime.py appcfg.py \
		backends_conversion.py bulkload_client.py bulkloader.py \
		dev_appserver.py download_appstats.py endpointscfg.py \
		gen_protorpc.py php_cli.py remote_api_shell.py \
		run_tests.py wrapper_util.py

MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:databases/py-MySQLdb@${PY_FLAVOR}

PHP_USE=	mysql=server
PHP_VARS=	gaedatadir+=php want_mysql_ver=55

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "${GAEDATADIR}" ${STAGEDIR}${DATADIR})
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/demos && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})
	(cd ${STAGEDIR}${PREFIX}/bin && \
	for S in ${GAESCRIPTS}; do \
	${INSTALL_SCRIPT} ${WRKSRC}/$${S} ${STAGEDIR}${DATADIR}; \
	${LN} ${LN_OPTS} ../${DATADIR_REL}/$${S} $${S}; \
	done)
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}

	(cd ${STAGEDIR}${DATADIR} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR} -f ${GAEDATADIR:Nphp} -q)

.include <bsd.port.mk>
