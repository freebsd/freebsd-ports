PORTNAME=	peering-manager
DISTVERSIONPREFIX=	v
DISTVERSION=	1.9.7
CATEGORIES=	net-mgmt python

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	BGP sessions management tool
WWW=		https://peering-manager.net/

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	\
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1:devel/py-Jinja2@${PY_FLAVOR} \
		bgpq4>0:net-mgmt/bgpq4 \
		${PYTHON_PKGNAMEPREFIX}django51>=5.1<5.2:www/py-django51@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-djangorestframework>=3.15:www/py-dj51-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-debug-toolbar>=5.0:www/py-dj51-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-filter>=25.1:www/py-dj51-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-netfields>=1.3:www/py-dj51-django-netfields@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-prometheus>=2.3:www/py-dj51-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-redis>=5.4:www/py-dj51-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-rq>=2.10:devel/py-dj51-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-tables2>=2.7:www/py-dj51-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-django-taggit>=6.1:www/py-dj51-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-drf-spectacular>=0.28:www/py-dj51-drf-spectacular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-drf-spectacular-sidecar>=2025:www/py-dj51-drf-spectacular-sidecar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj51-social-auth-app-django>=5.4:www/py-dj51-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dulwich>=0.22:devel/py-dulwich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=23.0.0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.7:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}napalm>=5.0:net-mgmt/py-napalm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}packaging>=23.2:devel/py-packaging@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.1:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-pool>=3.1:databases/py-psycopg-pool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyixapi>=0.2:net-mgmt/py-pyixapi@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pynetbox>=7.3:net-mgmt/py-pynetbox@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.5.4:security/py-social-auth-core@${PY_FLAVOR}

USES=		cpe pgsql:13+ python:3.10-3.12
CPE_VENDOR=	${PORTNAME}
CPE_PRODUCT=	${PORTNAME:S/-/_/}
USE_GITHUB=	yes
USE_RC_SUBR=	peering_manager_rq

NO_ARCH=	yes
NO_BUILD=	yes
SUB_FILES=	gunicorn.conf.py 850.peeringmanager-housekeeping
SUB_LIST=	WWWDIR=${WWWDIR} PORTNAME=${PORTNAME} WSGI_APP=peering_manager.wsgi PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER}

PORTDOCS=	*

OPTIONS_DEFINE=	DOCS
OPTIONS_DEFAULT=REDIS
OPTIONS_RADIO=	KVBACKENDS
OPTIONS_RADIO_KVBACKENDS=	REDIS VALKEY

KVBACKENDS_DESC=Key Value Storage Backends
REDIS_DESC=	Redis Key Value Backend support
VALKEY_DESC=	Valkey Key Value Backend support

REDIS_RUN_DEPENDS=	redis>=8.2.1:databases/redis
VALKEY_RUN_DEPENDS=	valkey>=1.0:databases/valkey

FIND_EXPR=	"! -name *.orig ! -name .gitattributes ! -name .gitignore ! -name .gitattributes ! -name .isort.cfg ! -name .pre-commit-config.yaml ! -name .readthedocs.yaml ! -name CHANGELOG.md ! -name LICENSE ! -name README.md ! -name mkdocs.yaml ! -name poetry.lock ! -name pyproject.toml ! -name requirements.txt ! -name configuration.example.py ! -path */.github ! -path */.github/* ! -path */docs ! -path */docs/* -prune"

do-install:
	${MKDIR} ${STAGEDIR}${WWWDIR}
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/daily
	${ECHO} "@owner www" >> ${TMPPLIST}
	${ECHO} "@group www" >> ${TMPPLIST}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} . ${STAGEDIR}${WWWDIR} ${FIND_EXPR})
	${FIND} -s ${STAGEDIR}${PREFIX}/www/${PORTNAME} -not -type d | ${SORT} | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/||' >> ${TMPPLIST}
	${FIND} -s ${STAGEDIR}${PREFIX}/www/${PORTNAME} -type d -empty | ${SORT} -r | \
		${SED} -e 's|^${STAGEDIR}${PREFIX}/|@dir |' >> ${TMPPLIST}
	${INSTALL_DATA} ${WRKDIR}/gunicorn.conf.py ${STAGEDIR}${WWWDIR}/gunicorn.conf.py.sample
	${INSTALL_DATA} ${WRKSRC}/peering_manager/configuration.example.py ${STAGEDIR}${WWWDIR}/peering_manager/configuration.py.sample
	${INSTALL_DATA} ${WRKDIR}/850.peeringmanager-housekeeping ${STAGEDIR}${PREFIX}/etc/periodic/daily/850.peeringmanager-housekeeping
	${ECHO} "@sample ${WWWDIR}/gunicorn.conf.py.sample" >> ${TMPPLIST}
	${ECHO} "@sample ${WWWDIR}/peering_manager/configuration.py.sample" >> ${TMPPLIST}
	${ECHO} "etc/periodic/daily/850.peeringmanager-housekeeping" >> ${TMPPLIST}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}
.for f in CHANGELOG.md  README.md
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
