# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-appengine
PORTVERSION=	1.9.2
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	https://commondatastorage.googleapis.com/appengine-sdks/featured/
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

LICENSE=	APACHE20 BSD3CLAUSE GPLv2 LGPL21 MIT MPL PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:${PORTSDIR}/security/py-pycrypto

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES MYSQL PHP
OPTIONS_DEFAULT=	MYSQL

PORTDATA=	*
PORTEXAMPLES=	*
PLIST_FILES=	${GAESCRIPTS:C,^| ,bin/&,g}

USE_PYTHON=	2
USES=		gettext shebangfix zip

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

LN_OPTS=	-sf

GAEDATADIR=	google lib new_project_template tools
GAESCRIPTS=	_php_runtime.py _python_runtime.py api_server.py appcfg.py \
		backends_conversion.py bulkload_client.py bulkloader.py \
		dev_appserver.py download_appstats.py endpointscfg.py \
		gen_protorpc.py google_sql.py old_dev_appserver.py php_cli.py \
		remote_api_shell.py run_tests.py wrapper_util.py

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:${PORTSDIR}/databases/py-MySQLdb
.endif
.if ${PORT_OPTIONS:MPHP}
GAEDATADIR+=	php
USE_MYSQL=	server
WANT_MYSQL_VER=	55
.endif

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for D in ${GAEDATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${STAGEDIR}${DATADIR})
.endfor
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} demos ${STAGEDIR}${EXAMPLESDIR})
.for S in ${GAESCRIPTS}
	${INSTALL_SCRIPT} ${WRKSRC}/${S} ${STAGEDIR}${DATADIR}
	${LN} ${LN_OPTS} ${DATADIR}/${S} ${STAGEDIR}${PREFIX}/bin/${S}
.endfor
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}

post-install:
	(cd ${STAGEDIR}${DATADIR} && \
	${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py -d ${DATADIR} -f ${GAEDATADIR:Nphp} -q)

.include <bsd.port.mk>
