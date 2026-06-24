PORTNAME=	bunkerweb
DISTVERSION=	1.6.11
PORTREVISION=	1
CATEGORIES=	www security

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Self-hosted web application firewall and security platform
WWW=		https://github.com/bunkerity/bunkerweb

LICENSE=	AGPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE.md

USES=		lua:51 python:3.11+,run shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	bunkerity
GH_PROJECT=	bunkerweb
GH_TAGNAME=	v${DISTVERSION}

RUN_DEPENDS=	openresty:www/openresty \
		${PYTHON_PKGNAMEPREFIX}Jinja2>0:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pydantic-settings>0:devel/py-pydantic-settings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}schedule>0:devel/py-schedule@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}user_agents>0:devel/py-user_agents@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlalchemy20>0:databases/py-sqlalchemy20@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sqlite3>0:databases/py-sqlite3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymysql>0:databases/py-pymysql@${PY_FLAVOR} \
		${LUA_MODLIBDIR}/cjson.so:devel/lua-cjson@${LUA_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bcrypt>0:security/py-bcrypt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}biscuit-auth>0:security/py-biscuit-auth \
		${PYTHON_PKGNAMEPREFIX}passlib>0:security/py-passlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}docker>0:sysutils/py-docker@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}kubernetes>0:sysutils/py-kubernetes@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psutil>0:sysutils/py-psutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}defusedcsv>=3.0.0:devel/py-defusedcsv@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}openpyxl>0:textproc/py-openpyxl@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}qrcode>0:textproc/py-qrcode@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}regex>0:textproc/py-regex@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cachelib>0:www/py-cachelib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}fastapi>0:www/py-fastapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask>0:www/py-flask@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Flask-Login>0:www/py-flask-login@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask-session>0:www/py-flask-session@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}flask_wtf>0:www/py-flask-wtf@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}slowapi>0:www/py-slowapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}uvicorn>0:www/py-uvicorn@${PY_FLAVOR}

LIB_DEPENDS=    libmaxminddb.so:net/libmaxminddb

USE_RC_SUBR=	bunkerweb \
		bunkerweb_api \
		bunkerweb_scheduler \
		bunkerweb_ui

SHEBANG_GLOB=	*.py *.sh

USERS=		bunkerweb
GROUPS=		bunkerweb

NO_ARCH=	yes
NO_BUILD=	yes

DATADIR=	${PREFIX}/share/${PORTNAME}

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC}/src && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR})

	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/plugins
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/${PORTNAME}/pro/plugins

	${MKDIR} ${STAGEDIR}/var/cache/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/cache/${PORTNAME}/bunkernet
	${MKDIR} ${STAGEDIR}/var/lib/${PORTNAME}
	${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}

post-install:
	${FIND} ${STAGEDIR}${DATADIR} -type f -name '*.sh' -exec ${CHMOD} 0755 {} \;
	${CHMOD} 0755 ${STAGEDIR}${DATADIR}/common/gen/main.py
	${CHMOD} 0755 ${STAGEDIR}${DATADIR}/common/gen/save_config.py

.include <bsd.port.mk>
