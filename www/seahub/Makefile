PORTNAME=	seahub
DISTVERSIONPREFIX=	v
DISTVERSION=	${SEAHUB_VER}
DISTVERSIONSUFFIX=	-server
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	ultima@FreeBSD.org
COMMENT=	Web frontend for Seafile
WWW=		https://github.com/haiwen/seahub

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR}

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/www/haiwen/seafile-server/seafile/bin/seaf-server:net-mgmt/seafile-server \
		${PYTHON_PKGNAMEPREFIX}django42>=0:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-statici18n>=2.3:www/py-django-statici18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-webpack-loader>=1.7:www/py-django-webpack-loader@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-picklefield>=3.1:www/py-django-picklefield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-formtools>=2.3:www/py-django-formtools@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangosaml2>=1.5:www/py-djangosaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.14:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-dateutil>=2.8:devel/py-python-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyjwt>=2.6:www/py-pyjwt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.20:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-cas>=1.6:security/py-python-cas@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pysaml2>=7.2:security/py-pysaml2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests-oauthlib>=1.3:www/py-requests-oauthlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}future>=0.18:devel/py-future@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=20.1:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mysqlclient>=2.1:databases/py-mysqlclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>=7.3:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.2:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}chardet>=5.1:textproc/py-chardet@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cffi>=1.15:devel/py-cffi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-simple-captcha>=0.5:www/py-django-simple-captcha@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=3.0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=5.0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-ldap>=3.4:net/py-python-ldap@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}setuptools>=3.4:devel/py-setuptools@${PY_FLAVOR}

		#${PYTHON_PKGNAMEPREFIX}captcha>=0.4:www/py-captcha@${PY_FLAVOR} \

USES=		gettext-tools:build python shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	haiwen
SHEBANG_FILES=	*.sh tests/*.sh *.template *.py tools/*.py seahub/*.py \
		scripts/*.sh scripts/upgrade/*.sh *.sh scripts/build/*.py \
		scripts/*.py scripts/upgrade/*.py

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
	(cd ${WRKSRC}; (for file in run-seahub.sh.template \
		send_user_notifications.sh.template setenv.sh.template; do \
		${CP} $$file $${file%%.template}; \
		done))
	${REINPLACE_CMD} -E 's/stat.+\$$/stat -f %Su $$/' ${WRKSRC}/scripts/seafile.sh
	${REINPLACE_CMD} 's/%%SEAFILE_USER%%/${USERS:[1]}/ ; s/%%SEAFILE_GROUP%%/${GROUPS:[1]}/' \
			${WRKSRC}/scripts/setup-seafile.sh ${WRKSRC}/scripts/setup-seafile-mysql.py
# Fix python hardcodings
	${REINPLACE_CMD} 's/python3\.[0-9]/${PYTHON_VERSION}/g; s/python3 /${PYTHON_VERSION} / ; \
			s/PYTHON=python3/PYTHON=${PYTHON_VERSION}/ ; s|/python3/|/${PYTHON_VERSION}/|g' \
		${WRKSRC}/scripts/*.sh \
		${WRKSRC}/scripts/setup-seafile-mysql.py \
		${WRKSRC}/scripts/upgrade/upgrade_[7-9].[0-9]_[7-9].[0-9].sh
	${REINPLACE_CMD} 's/python/${PYTHON_VERSION}/' \
		${WRKSRC}/scripts/upgrade/regenerate_secret_key.sh
	${FIND} ${WRKSRC} -name "*.bak" -exec ${RM} {} \;
	${FIND} ${WRKSRC} -name "*.orig" -exec ${RM} {} \;
	${RM} ${WRKSRC}/.gitignore

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/runtime/ \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR} ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR} \
		${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR}/custom \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEAHUBDIR} \
	"! -name Makefile ! -name seahub.conf ! -name avatars \
	! -name default-non-register.jpg ! -name default.png ! -name groups")
	(cd ${WRKSRC}/media && ${COPYTREE_SHARE} ./avatars \
		 ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR})
	${LN} -fs ../../../seahub-data/avatars \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR}/media/avatars
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/*.[ps][yh] ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}
	${INSTALL_SCRIPT} ${WRKSRC}/scripts/upgrade/*.[ps][yh] \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/upgrade
	(cd ${WRKSRC}/scripts && \
		${COPYTREE_SHARE} "upgrade/sql" ${STAGEDIR}${PREFIX}/${SEAFILE_SERVER})

.include "${.CURDIR}/../../net-mgmt/seafile-server/Makefile.include"

.include <bsd.port.mk>
