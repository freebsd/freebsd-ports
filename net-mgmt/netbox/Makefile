PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	4.7.5
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
# - devel/py-dj61-django-rq
# - www/py-dj61-django-filter
# - www/py-dj61-django-tables2
# - www/py-dj61-djangorestframework
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django61>=6.1.3<6.2:www/py-django61@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-cors-headers>=4.9.0<5:www/py-dj61-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-debug-toolbar>=8.0.0<9:www/py-dj61-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-filter>=26.2<27:www/py-dj61-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-htmx>=1.29.0<2:www/py-dj61-django-htmx@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-mptt>=0.18.0<0.19:www/py-dj61-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-prometheus>=2.4.0<2.6:www/py-dj61-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-redis>=7.0.0<8:www/py-dj61-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-rich>=2.2.0<3:www/py-dj61-django-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-rq>=4.2.0<4.3:devel/py-dj61-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-storages>=1.14.6<2:www/py-dj61-django-storages@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-tables2>=3.0.1<3.1:www/py-dj61-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-taggit>=7.0.0<8:www/py-dj61-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-django-timezone-field>=7.2.2<8:www/py-dj61-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-djangorestframework>=3.18.3<3.19.0:www/py-dj61-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-drf-spectacular>=0.30.0<1:www/py-dj61-drf-spectacular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-drf-spectacular-sidecar>=2026.10.1:www/py-dj61-drf-spectacular-sidecar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-social-auth-app-django>=6.1.0<7:www/py-dj61-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-sorl-thumbnail>=13.4.0<14:graphics/py-dj61-sorl-thumbnail@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-strawberry-graphql>=0.327.1<1:devel/py-dj61-strawberry-graphql@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj61-strawberry-graphql-django>=0.88.0<1:www/py-dj61-strawberry-graphql-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}colorama>=0.4.6<1:devel/py-colorama@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pgware>=1.0.0<2:databases/py-django-pgware@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.12<7:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=26.2.0:www/py-gunicorn@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.6<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}jsonschema>=4.26.0<5:devel/py-jsonschema@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.11.2<4:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs>=1.6.1<2:textproc/py-mkdocs@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=1.0.8<2:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings-python>=2.0.10:textproc/py-mkdocstrings-python@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=1.3.0<2:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}nh3>=0.3.7<1:www/py-nh3@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=13.0.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.3.6<4:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-c>=3.3.6<4:databases/py-psycopg-c@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg-pool>=3.3.3<4:databases/py-psycopg-pool@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pymdown-extensions>=12.1<14:textproc/py-pymdown-extensions@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pyyaml>=6.0.3<7:devel/py-pyyaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=8.1.0<9:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.34.2<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}rq>=2.12.0<3:devel/py-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core5>=5.2.0<6:security/py-social-auth-core5@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.10.0<4:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2026.6:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}zensical>=0.1.0<1:textproc/py-zensical@${PY_FLAVOR}

USES=		cpe pgsql:15+ python:3.12+
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
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj61-django-auth-ldap>0:www/py-dj61-django-auth-ldap
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
