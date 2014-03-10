# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	google-appengine
PORTVERSION=	1.8.6
PORTREVISION=	0
CATEGORIES=	www devel python
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTFILES=	${PORTNAME:S|-|_|}_${PORTVERSION}.zip

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Development tools for Google App Engine (SDK)

LICENSE=	APACHE20 BSD GPLv2 LGPL21 MIT MPL PSFL
LICENSE_COMB=	multi

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=${PYTHON_VER}:${PORTSDIR}/databases/py-sqlite3 \
		${PYTHON_PKGNAMEPREFIX}imaging>=1.1.6_2:${PORTSDIR}/graphics/py-imaging \
		${PYTHON_PKGNAMEPREFIX}pycrypto>=2.6:${PORTSDIR}/security/py-pycrypto

NO_BUILD=	yes

OPTIONS_DEFINE=	EXAMPLES MYSQL PHP
OPTIONS_DEFAULT=	MYSQL

PROJECTHOST=	googleappengine

USE_PYTHON=	2
USES=		gettext zip

WRKSRC=	${WRKDIR}/${PORTNAME:S,-,_,}

FIND_FILES=	${WRKSRC} -type f -name "*.py" -print0
FIND_FILES_BAK=	${WRKSRC} -type f -and \( -name "*.orig" -or -name "*.bak" \)

LN_OPTS=	-sf

XARGS_ARGS=	-0
REINPLACE_ARGS=	-e 's,/usr/bin/env python,&${PYTHON_VER},' -i.bak

GAEDATADIR=	google lib new_project_template php tools
GAESCRIPTS=	_php_runtime.py _python_runtime.py api_server.py appcfg.py \
		bulkload_client.py bulkloader.py dev_appserver.py \
		download_appstats.py endpointscfg.py gen_protorpc.py \
		google_sql.py old_dev_appserver.py remote_api_shell.py run_tests.py

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MMYSQL}
RUN_DEPENDS+=	${PYTHON_PKGNAMEPREFIX}MySQLdb>=1.2.3:${PORTSDIR}/databases/py-MySQLdb
.endif
.if ${PORT_OPTIONS:MPHP}
USE_MYSQL=	server
WANT_MYSQL_VER=	55
.endif

post-patch:
	@${FIND} ${FIND_FILES} | ${XARGS} ${XARGS_ARGS} ${REINPLACE_CMD}
	@${FIND} ${FIND_FILES_BAK} -delete

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
.for D in ${GAEDATADIR}
	@(cd ${WRKSRC} && ${COPYTREE_SHARE} ${D} ${STAGEDIR}${DATADIR})
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
