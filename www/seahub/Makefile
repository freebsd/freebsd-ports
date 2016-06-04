# $FreeBSD$

PORTNAME=	seahub
PORTVERSION=	5.1.7
DISTVERSIONPREFIX=	v
DISTVERSIONSUFFIX=	-pro
CATEGORIES=	www

MAINTAINER=	ultima1252@gmail.com
COMMENT=	Web frontend for Seafile

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	bash:shells/bash \
		${LOCALBASE}/www/haiwen/seafile-server/seafile/bin/seaf-server:net-mgmt/seafile \
		${PYTHON_PKGNAMEPREFIX}django18>=0:www/py-django18 \
		${PYTHON_PKGNAMEPREFIX}pytz>=0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}django-statici18n>=0:www/py-django-statici18n \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=0:www/py-djangorestframework \
		${PYTHON_PKGNAMEPREFIX}django_compressor>=0:www/py-django_compressor \
		${PYTHON_PKGNAMEPREFIX}django-post_office>=0:www/py-django-post_office \
		${PYTHON_PKGNAMEPREFIX}django-constance>=0:www/py-django-constance \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=0:www/py-gunicorn \
		${PYTHON_PKGNAMEPREFIX}flup>=0:www/py-flup \
		${PYTHON_PKGNAMEPREFIX}chardet>=0:textproc/py-chardet \
		${PYTHON_PKGNAMEPREFIX}dateutil>=0:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}six>=0:devel/py-six \
		${PYTHON_PKGNAMEPREFIX}openpyxl>=0:textproc/py-openpyxl \
		${PYTHON_PKGNAMEPREFIX}pillow>=0:graphics/py-pillow \
		${PYTHON_PKGNAMEPREFIX}MySQLdb>0:databases/py-MySQLdb

USE_GITHUB=	yes
GH_ACCOUNT=	haiwen

USES=		python:-2.7 shebangfix
SHEBANG_FILES=	*.sh tests/*.sh *.template *.py tools/*.py seahub/*.py

NO_BUILD=	yes

OPTIONS_DEFINE=		SEAFOBJ SEAFDAV NLS
OPTIONS_DEFAULT=	SEAFOBJ SEAFDAV
OPTIONS_SUB=		yes

SEAFOBJ_DESC=		Enable Seafile file object modeling support
SEAFDAV_DESC=		Enable Seafile WsgiDav-based support

SEAFOBJ_CONFIGURE_WITH=	seafobj
SEAFOBJ_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafobj>0:www/py-seafobj

SEAFDAV_CONFIGURE_WITH=	seafdav
SEAFDAV_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}seafdav>0:www/py-seafdav

NLS_USES=		gettext iconv
NLS_CONFIGURE_OFF=	--disable-nls

HAIWENDIR=	www/haiwen
SEAFILE_SERVER=	${HAIWENDIR}/seafile-server
SEAHUBDIR=	${SEAFILE_SERVER}/seahub
SEALIB=		${SEAFILE_SERVER}/seafile/lib
SITEPACKAGEDIR=	${SEAHUBDIR}/thirdpart
SEAHUB_DATA_DIR=	${HAIWENDIR}/seahub-data

USERS=		seafile
GROUPS=		${USERS}

USE_RC_SUBR=	${PORTNAME}
PLIST_SUB=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		SEAHUBDIR=${SEAHUBDIR} \
		HAIWENDIR=${HAIWENDIR} \
		SITEPACKAGEDIR=${SITEPACKAGEDIR}

SUB_FILES=	pkg-message

SUB_LIST+=	USERS=${USERS} \
		GROUPS=${GROUPS} \
		SEAFILE_SERVER=${SEAFILE_SERVER} \
		HAIWENDIR=${HAIWENDIR} \
		PYTHON=${PYTHON_VERSION}

do-patch:
	echo "${WRKSRC}..."
	@${MKDIR} ${WRKSRC}/runtime
	${CP} ${FILESDIR}/runtime_seahub.conf ${WRKSRC}/runtime/seahub.conf
	${REINPLACE_CMD} -e "s|SEAFILE_VERSION = '[0-9].[0-9].[0-9]'|SEAFILE_VERSION = '${PORTVERSION}'|" \
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
		${STAGEDIR}${PREFIX}/${SEAHUBDIR} ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR}
	${INSTALL} ${WRKSRC}/runtime/seahub.conf \
		${STAGEDIR}${PREFIX}/${SEAFILE_SERVER}/runtime/
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${PREFIX}/${SEAHUBDIR} \
	"! -name Makefile ! -name runtime ! -name seahub.conf ! -name avatars \
	! -name default-non-register.jpg ! -name default.png ! -name groups")
	(cd ${WRKSRC}/media && ${COPYTREE_SHARE} ./avatars \
		 ${STAGEDIR}${PREFIX}/${SEAHUB_DATA_DIR})
	${LN} -fs ${PREFIX}/${SEAHUB_DATA_DIR}/avatars \
		${STAGEDIR}${PREFIX}/${SEAHUBDIR}/media/avatars

.include <bsd.port.mk>
