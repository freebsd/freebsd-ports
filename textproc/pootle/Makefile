# Created by: Denis Pokataev <catone@cpan.org>
# $FreeBSD$

PORTNAME=	pootle
DISTVERSION=	2.8.2
CATEGORIES=	textproc

MAINTAINER=	ports@FreeBSD.org
COMMENT=	User-friendly web portal for simple translation process

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN=		Dependencies broken: Dependencies all pinned (==) not satisfied by ports
DEPRECATED=	Unamaintained, marked BROKEN for more than 5 months
EXPIRATION_DATE=	2020-01-14

RUN_DEPENDS=	translate-toolkit>=2.2.5:textproc/translate-toolkit \
		${PYTHON_PKGNAMEPREFIX}Babel>=2.5.1:devel/py-babel@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=2.0.0:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}country>=17.5.14:devel/py-country@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}cssmin>=0.2.0:www/py-cssmin@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dateutil>=2.6.1:devel/py-dateutil@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}diff-match-patch>=20121119:textproc/py-diff-match-patch@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dirsync>=2.2.2:sysutils/py-dirsync@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-allauth>=0.33.0:www/py-django-allauth@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-assets>=0.12:www/py-django-assets@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-bulk-update>=2.2.0:www/py-django-bulk-update@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-contact-form>=1.4.2:www/py-django-contact-form@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-contrib-comments>=1.7.3:www/py-django-contrib-comments@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-overextends>=0.4.3:www/py-django-overextends@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-redis>=4.8.0:www/py-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-rq>=0.9.6:devel/py-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-sortedm2m>=1.5.0:www/py-django-sortedm2m@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-statici18n>=1.4.0:www/py-django-statici18n@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonfield>=2.0.2:www/py-jsonfield@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}lxml>=3.5:devel/py-lxml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.9:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pathlib>=1.0.1:devel/py-pathlib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}python-Levenshtein>=0.12.0:devel/py-python-Levenshtein@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>=2017.2:devel/py-pytz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}raven>=6.1.0:devel/py-raven@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}scandir>=1.5:sysutils/py-scandir@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}stemming>=1.0.1:textproc/py-stemming@${PY_FLAVOR}

USES=		gettext python:2.7 tar:bzip2 shebangfix
USE_PYTHON=	autoplist distutils
USE_GITHUB=	yes

GH_ACCOUNT=	translate

NO_ARCH=	yes

USERS=		pootle
GROUPS=		pootle

SUB_LIST+=	POOTLEUSER="${USERS}" \
		POOTLEGROUP="${GROUPS}" \
		POOTLERUNDIR="/var/run/${PORTNAME}/"

USE_RC_SUBR=	pootle
SUB_LIST+=	PYTHON_CMD="${PYTHON_CMD}"

PORTDOCS=	AUTHORS CONTRIBUTING.rst INSTALL README.rst

OPTIONS_DEFINE=	DOCS
OPTIONS_GROUP=	DB
DB_DESC=	Database backend
OPTIONS_GROUP_DB=MYSQL PGSQL SQLITE
OPTIONS_DEFAULT=SQLITE

MYSQL_USES=		mysql:client
MYSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mysqlclient>=1.3.3:databases/py-mysqlclient@${PY_FLAVOR}
PGSQL_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}psycopg2>=2.4.5:databases/py-psycopg2@${PY_FLAVOR}
SQLITE_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sqlite3>=0:databases/py-sqlite3@${PY_FLAVOR}

post-extract:
	${RM} ${WRKSRC}/tests/__init__.py # prevent conflict with py-django-bulk-update dependency
pre-configure:
	# switch off pip checks
	${REINPLACE_CMD} -e '/^check_pep440_versions()/d' ${WRKSRC}/setup.py
	# relax versions for packaging
	${REINPLACE_CMD} -e "s/==/>=/g" \
		-e "s/~=/>=/g" \
		-e "s/,<=.*//g" \
		${WRKSRC}/requirements/base.txt
	# fix django-bulk-update invocations
	${REINPLACE_CMD} -e "s/bulk_update.helper/django_bulk_update.helper/g" \
		${WRKSRC}/pootle/core/batch.py \
		${WRKSRC}/pootle/core/bulk.py \
		${WRKSRC}/pootle/apps/pootle_store/migrations/0054_clean_abs_file_paths.py \
		${WRKSRC}/pootle/apps/pootle_fs/plugin.py

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}/${DOCSDIR}
.for docs in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${docs} ${STAGEDIR}/${DOCSDIR}
.endfor

.include <bsd.port.mk>
