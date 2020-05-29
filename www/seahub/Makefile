# $FreeBSD$

PORTNAME=	seahub
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAHUB_VER}
DISTVERSIONSUFFIX=	-pro
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Web frontend for Seafile

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR}

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/www/haiwen/seafile-server/seafile/bin/seaf-server:net-mgmt/seafile-server \
		${PYTHON_PKGNAMEPREFIX}django111>=0:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-statici18n>=0:www/py-django-statici18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-post_office>=0:www/py-django-post_office@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-webpack-loader>=0:www/py-django-webpack-loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-picklefield>=0:www/py-django-picklefield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-formtools>=0:www/py-django-formtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-simple-captcha>=0:www/py-django-simple-captcha@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework311>=0:www/py-djangorestframework311@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=0:www/py-requests@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=0:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=0:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=0:www/py-requests-oauthlib@${PY_FLAVOR}

USES=		gettext-tools:build python:3.6+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
SHEBANG_FILES=	*.sh tests/*.sh *.template *.py tools/*.py seahub/*.py

NO_ARCH=	yes

OPTIONS_DEFINE=		SEAFOBJ SEAFDAV NLS
OPTIONS_DEFAULT=	SEAFOBJ SEAFDAV
OPTIONS_SUB=		yes

ALL_TARGET=	locale

SEAFOBJ_DESC=		Enable Seafile file object modeling support
SEAFDAV_DESC=		Enable Seafile WsgiDav-based support

SEAFOBJ_CONFIGURE_WITH=	seafobj
SEAFOBJ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafobj>0:www/py-seafobj@${PY_FLAVOR}

SEAFDAV_CONFIGURE_WITH=	seafdav
SEAFDAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafdav>0:www/py-seafdav@${PY_FLAVOR}

NLS_USES=		gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls

USE_RC_SUBR=	${PORTNAME}

SUB_FILES=	pkg-message

post-patch:
	${REINPLACE_CMD} -Ee "s|SEAFILE_VERSION = '[0-9]+\.[0-9]+\.[0-9]+'|SEAFILE_VERSION = '${SEAFILE_VER}'|" \
			 ${WRKSRC}/seahub/settings.py
	${REINPLACE_CMD} -e 's|##FIX_WWWDIR##|${PREFIX}/${HAIWENDIR}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_SEALIB##|${PREFIX}/${SEALIB}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_SITEPACKAGEDIR##|${PREFIX}/${SITEPACKAGEDIR}|' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##PYTHON_VERSION##|${PYTHON_VERSION}|g' ${WRKSRC}/*.template
	${REINPLACE_CMD} -e 's|##FIX_LOCALBASE##|${LOCALBASE}|' ${WRKSRC}/*.template
	${FIND} ${WRKSRC} -name "*.bak" -exec ${RM} {} \;
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;
	(cd ${WRKSRC}; (for file in run-seahub.sh.template \
		send_user_notifications.sh.template setenv.sh.template; do \
		${CP} $$file $${file%%.template}; \
		done))
	${RM} ${WRKSRC}/.gitignore

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/runtime/ \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR} ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR} \
		${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR}/custom
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEAHUBDIR} \
	"! -name Makefile ! -name seahub.conf ! -name avatars \
	! -name default-non-register.jpg ! -name default.png ! -name groups")
	(cd ${WRKSRC}/media && ${COPYTREE_SHARE} ./avatars \
		 ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR})
	${LN} -fs ../../../seahub-data/avatars \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR}/media/avatars

.include "${.CURDIR}/../../net-mgmt/seafile-server/Makefile.include"

.include <bsd.port.mk>
