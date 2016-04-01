# $FreeBSD$

PORTNAME=	seahub
PORTVERSION=	4.0.5
PORTREVISION=	1
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www
MASTER_SITES=	https://pypi.python.org/packages/source/p/pip/:pip \
		https://pypi.python.org/packages/source/p/pbr/:pbr \
		https://pypi.python.org/packages/source/l/lockfile/:lockfile \
		https://pypi.python.org/packages/source/s/six/:six \
		https://pypi.python.org/packages/source/g/gunicorn/:gunicorn \
		https://pypi.python.org/packages/source/f/flup/:flup \
		https://pypi.python.org/packages/source/d/daemon/:daemon \
		https://pypi.python.org/packages/source/c/chardet/:chardet \
		https://pypi.python.org/packages/source/p/python-dateutil/:dateutil \
		https://pypi.python.org/packages/source/P/Pillow/:Pillow \
		https://pypi.python.org/packages/source/D/Django/:Django \
		http://downloads.reviewboard.org/releases/Djblets/0.6/:Djblets
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pip-1.5.6.tar.gz:pip \
		pbr-0.10.0.tar.gz:pbr \
		lockfile-0.10.2.tar.gz:lockfile \
		six-1.8.0.tar.gz:six \
		gunicorn-18.0.tar.gz:gunicorn \
		flup-1.0.2.tar.gz:flup \
		daemon-1.1.tar.gz:daemon \
		chardet-2.3.0.tar.gz:chardet \
		python-dateutil-2.2.tar.gz:dateutil \
		Pillow-2.6.1.zip:Pillow \
		Django-1.5.9.tar.gz:Django \
		Djblets-0.6.14.tar.gz:Djblets
DIST_SUBDIR=	${PORTNAME}

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Web frontend for Seafile

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${LOCALBASE}/www/haiwen/seafile-server/seafile/bin/seaf-server:net-mgmt/seafile \
		bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		python:2 shebangfix
SHEBANG_FILES=	*.sh *.template

NO_BUILD=	yes

OPTIONS_DEFINE=		SEAFOBJ SEAFDAV NLS SITEPACKAGES
OPTIONS_DEFAULT=	SEAFOBJ SEAFDAV
OPTIONS_SUB=		yes

SEAFOBJ_DESC=		Enable Seafile file object modeling support
SEAFDAV_DESC=		Enable Seafile WsgiDav-based support
SITEPACKAGES_DESC=	Install python packages under thirdpart directory

SEAFOBJ_CONFIGURE_WITH=	seafobj
SEAFOBJ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafobj>0:www/py-seafobj

SEAFDAV_CONFIGURE_WITH=	seafdav
SEAFDAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafdav>0:www/py-seafdav

NLS_USES=		gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls

VIRTUALENV=	${WRKDIR}/virtualenv
HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEAHUBDIR=	${SEAFILE_SERVER}/seahub
SEALIB=		${SEAFILE_SERVER}/seafile/lib
SITEPACKAGEDIR=	${SEAHUBDIR}/thirdpart

SEAFILE_USERNAME?=	www
SEAFILE_GROUPNAME?=	${SEAFILE_USERNAME}

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	SEAFILE_USERNAME=${SEAFILE_USERNAME} \
		SEAFILE_GROUPNAME=${SEAFILE_GROUPNAME} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		SEAHUBDIR=${SEAHUBDIR} \
		HAIWENDIR=${HAIWENDIR} \
		SITEPACKAGEDIR=${SITEPACKAGEDIR}

PORT_SITE_PKGS=	pip-1.5.6 \
		pbr-0.10.0 \
		pillow-2.6.1 \
		lockfile-0.10.2 \
		six-1.8.0 \
		gunicorn-18.0 \
		flup-1.0.2 \
		daemon-1.1 \
		chardet-2.3.0 \
		python-dateutil-2.2 \
		Django-1.5.9 \
		Djblets-0.6.14

.include <bsd.port.options.mk>

post-install-sitepackages:
	@${MKDIR} ${VIRTUALENV}${LOCALBASE}/bin ${VIRTUALENV}${LOCALBASE}/include \
		${VIRTUALENV}${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages
	(cd ${WRKSRC}; export PYTHONPATH=${VIRTUALENV}${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages; \
		(for sp_pkg in ${PORT_SITE_PKGS}; do \
		cd ${WRKDIR}/$$sp_pkg && ${ECHO_CMD} -e "[install]\nprefix=${VIRTUALENV}${LOCALBASE}" >> setup.cfg && \
		if [ "$$sp_pkg" == "Djblets-0.6.14" ]; then ${REINPLACE_CMD} -e "s|PIL|Pillow|" ./Djblets.egg-info/requires.txt; \
			${REINPLACE_CMD} -e "s|PIL|Pillow|" ./setup.py; fi && \
		${PYTHON_CMD} setup.py install; \
		done))
	(cd ${VIRTUALENV}${LOCALBASE}/lib/${PYTHON_VERSION}/site-packages && \
		${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SITEPACKAGEDIR})

.if ${PORT_OPTIONS:MSITEPACKAGES}
post-install:post-install-sitepackages
.endif

post-patch:
	echo "${WRKSRC}..."
	@${MKDIR} ${WRKSRC}/runtime
	${CP} ${FILESDIR}/runtime_seahub.conf ${WRKSRC}/runtime/seahub.conf
	${REINPLACE_CMD} -e "s|SEAFILE_VERSION = '3.0.0'|SEAFILE_VERSION = '${PORTVERSION}'|" ${WRKSRC}/seahub/settings.py
	${REINPLACE_CMD} -e 's|##FIX_HAIWENDIR##|${PREFIX}/${HAIWENDIR}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_SEALIB##|${PREFIX}/${SEALIB}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_SITEPACKAGEDIR##|${PREFIX}/${SITEPACKAGEDIR}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##PYTHON_VERSION##|${PYTHON_VERSION}|g' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_LOCALBASE##|${LOCALBASE}|' ${WRKSRC}/*.template
	${FIND} ${WRKSRC} -name "*.bak" -exec ${RM} {} \;
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;
	(cd ${WRKSRC}; (for file in run-seahub.sh.template \
				   send_user_notifications.sh.template setenv.sh.template; do \
		cp $$file $${file%%.template}; \
		done))
	${RM} ${WRKSRC}/.gitignore

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/runtime/ \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR}
	${INSTALL} ${WRKSRC}/runtime/seahub.conf \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/runtime/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEAHUBDIR})

.include <bsd.port.mk>
