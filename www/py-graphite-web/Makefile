# Created by: Evan Sarmiento <esarmiento@wayfair.com>

PORTNAME=	graphite-web
PORTVERSION=	1.1.8
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Enterprise scalable realtime graphing platform

LICENSE=	APACHE20

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}carbon>=${PORTVERSION}:databases/py-carbon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0.4.2:www/py-django-tagging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=1.8<3.1:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scandir>=0:sysutils/py-scandir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing>=0:devel/py-pyparsing@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		xorg-fonts-truetype>=0:x11-fonts/xorg-fonts-truetype \
		bash:shells/bash

USES=		cpe python:3.5+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project
CPE_VENDOR=	graphite_project
CPE_PRODUCT=	graphite
USE_PYTHON=	distutils
SHEBANG_FILES=	bin/build-index.sh

CONFLICTS_INSTALL=	py??-graphite-web

FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} WWWOWN=${WWWOWN} \
		WWWGRP=${WWWGRP} DATADIR=${DATADIR}
PLIST_SUB=	WWWOWN=${WWWOWN} WWWGRP=${WWWGRP}

post-patch:
	@${RM} ${WRKSRC}/bin/build-index.sh.orig
	@${RM} ${WRKSRC}/bin/run-graphite-devel-server.py
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' \
		-e 's|%%DATADIR%%|${DATADIR}|' \
		-e 's|%%PYTHON_SITELIBDIR%%|${PYTHON_SITELIBDIR}|' \
		${WRKSRC}/bin/build-index.sh \
		${WRKSRC}/conf/graphite.wsgi.example \
		${WRKSRC}/setup.cfg \
		${WRKSRC}/setup.py \
		${WRKSRC}/webapp/graphite/local_settings.py.example

post-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}/examples
	@(cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/examples)
	@${MKDIR} ${STAGEDIR}${DATADIR}/content
	@(cd ${WRKSRC}/webapp/content && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/content)
	@${MKDIR} ${STAGEDIR}/var/log/graphite/webapp
	@${MKDIR} ${STAGEDIR}/var/db/graphite
	@${CP} ${STAGEDIR}${PYTHON_SITELIBDIR}/graphite/local_settings.py.example ${STAGEDIR}${PREFIX}/etc/graphite/local_settings.py.example
	@${LN} -s ${PREFIX}/etc/graphite/local_settings.py ${STAGEDIR}${PYTHON_SITELIBDIR}/graphite/local_settings.py

.include <bsd.port.mk>
