# Created by: Evan Sarmiento <esarmiento@wayfair.com>

PORTNAME=	graphite-web
PORTVERSION=	1.1.10
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Enterprise scalable realtime graphing platform

LICENSE=	APACHE20

DEPRECATED=	No support for newer versions of Django
EXPIRATION_DATE=	2022-06-30

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}cairo>=1.8.10:graphics/py-cairo@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}carbon>=${PORTVERSION}:databases/py-carbon@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-tagging>=0.4.6:www/py-django-tagging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django22>=1.8<3.1:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyparsing2>=2.3.0:devel/py-pyparsing2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-memcached>=1.58:databases/py-python-memcached@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}six>0:devel/py-six@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}txamqp>=0.8:net/py-txamqp@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urllib3>0:net/py-urllib3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whisper>0:databases/py-whisper@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}whitenoise>=4.1.2:www/py-whitenoise@${PY_FLAVOR} \
		bash:shells/bash \
		xorg-fonts-truetype>=0:x11-fonts/xorg-fonts-truetype

USES=		cpe python shebangfix
CPE_VENDOR=	graphite_project
CPE_PRODUCT=	graphite
USE_GITHUB=	yes
GH_ACCOUNT=	graphite-project
USE_PYTHON=	distutils
SHEBANG_FILES=	bin/build-index.sh

CONFLICTS_INSTALL=	py??-graphite-web

FETCH_ARGS=	-o ${DISTNAME}${EXTRACT_SUFX}
NO_ARCH=	yes
SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} \
		PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}
PLIST_SUB=	WWWGRP=${WWWGRP} \
		WWWOWN=${WWWOWN}

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} > 30900
BROKEN=		Python-3.9 is not supported
.endif

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
