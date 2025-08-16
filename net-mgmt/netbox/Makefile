PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	4.3.6
CATEGORIES=	net-mgmt python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool
WWW=		https://github.com/netbox-community/netbox

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# NetBox has fixed Python package dependencies listed in "requirements.txt"
# which are not checked during build/runtime because they're usually installed
# via devel/py-pip.
#
# As a rule, slight deviations are usually not a problem, but there are a few
# Django packages that are known for regressions in conjunction with NetBox and
# should therefore only be updated with caution.
#
# - devel/py-dj52-django-rq
# - www/py-dj52-django-filter
# - www/py-dj52-django-tables2
# - www/py-dj52-djangorestframework
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django52>=5.2.3<5.3:www/py-django52@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-cors-headers>=4.7.0<5:www/py-dj52-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-debug-toolbar>=5.2.0<6:www/py-dj52-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-filter>=25.1<26:www/py-dj52-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-htmx>=1.23.2<2:www/py-dj52-django-htmx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-mptt>=0.17.0<0.18:www/py-dj52-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-prometheus>=2.4.1<2.5:www/py-dj52-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-redis>=6.0.0<7:www/py-dj52-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-rich>=2.0.0<3:www/py-dj52-django-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-rq>=3.0.1<3.2:devel/py-dj52-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-storages>=1.14.6<2:www/py-dj52-django-storages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-tables2>=2.7.5<2.8:www/py-dj52-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-taggit>=6.1.0<7:www/py-dj52-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-django-timezone-field>=7.1<8:www/py-dj52-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-djangorestframework>=3.16.1<3.17.0:www/py-dj52-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-drf-spectacular>=0.28.0<1:www/py-dj52-drf-spectacular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-drf-spectacular-sidecar>=2025.8.1:www/py-dj52-drf-spectacular-sidecar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-social-auth-app-django>=5.5.1<6:www/py-dj52-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-strawberry-graphql>=0.278.1<0.300:devel/py-dj52-strawberry-graphql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj52-strawberry-graphql-django>=0.65.1<1:www/py-dj52-strawberry-graphql-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.11<7:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.24.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.8<3.9:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>=9.6.16<10:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.30.0<1:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings-python>0:textproc/py-mkdocstrings-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=1.3.0<2:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nh3>=0.3.0<1:www/py-nh3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=11.2.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.2.9<4:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-c>=3.2.9<4:databases/py-psycopg-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-pool>=3.2.6<4:databases/py-psycopg-pool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.32.3<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2.4.1<3:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.7.0<5:security/py-social-auth-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.8.0<4:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2025.2:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.1<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=23.0.0<24:www/py-gunicorn@${PY_FLAVOR}

USES=		cpe pgsql:14+ python:3.10+
CPE_VENDOR=	netbox
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	850.netbox-housekeeping.sample netbox_rq.sample netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_GROUP=	BACKENDS
OPTIONS_GROUP_BACKENDS=	GIT LDAP S3 SENTRY

GIT_DESC=	Git backend support
LDAP_DESC=	LDAP backend support
S3_DESC=	Amazon S3 backend support
SENTRY_DESC=	Sentry monitoring support

GIT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>0:devel/py-dulwich@${PY_FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj52-django-auth-ldap>0:www/py-dj52-django-auth-ldap
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR}
SENTRY_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}sentry-sdk>0:devel/py-sentry-sdk@${PY_FLAVOR}

do-install:
	cd ${WRKSRC}/netbox ; \
	for src in $$( ${FIND} . ! -name '*.bak' -a ! -name '*.orig' ) ; do \
		dst=${STAGEDIR}${DATADIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} "$$src" "$$dst" ; \
		fi \
	done
	cd ${WRKSRC} && ${COPYTREE_SHARE} docs ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/mkdocs.yml ${STAGEDIR}${DATADIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/850.netbox-housekeeping.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netbox_rq.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netboxrc.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/apache.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/gunicorn.py ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/nginx.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
