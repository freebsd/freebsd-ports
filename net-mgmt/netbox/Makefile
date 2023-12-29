PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	3.6.9
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
# - devel/py-dj42-django-rq
# - www/py-dj42-django-filter
# - www/py-dj42-django-tables2
# - www/py-dj42-djangorestframework
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django42>=4.2.6<4.3:www/py-django42@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-cors-headers>=4.3.1<5:www/py-dj42-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-debug-toolbar>=4.2.0<5:www/py-dj42-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-filter>=23.5<24:www/py-dj42-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-graphiql-debug-toolbar>=0.2.0<1:www/py-dj42-django-graphiql-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-mptt>=0.14.0<0.15:www/py-dj42-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-prometheus>=2.3.1<2.4:www/py-dj42-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-redis>=5.4.0<6:www/py-dj42-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-rich>=1.8.0<2:www/py-dj42-django-rich@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-rq>=2.9.0<2.11:devel/py-dj42-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-tables2>=2.7<2.8:www/py-dj42-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-taggit>=4.0.0<5:www/py-dj42-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-django-timezone-field>=6.1.0<7:www/py-dj42-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-djangorestframework>=3.14.0<3.15.0:www/py-dj42-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-drf-spectacular>=0.27.0<1:www/py-dj42-drf-spectacular@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-drf-spectacular-sidecar>=2023.12.1:www/py-dj42-drf-spectacular-sidecar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj42-graphene-django>=3.0.0<3.0.0_99:devel/py-dj42-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=6.0.0<7:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}feedparser>=6.0.8<7:textproc/py-feedparser@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.1.2<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7<3.4:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>=9.4.6<10:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.24.0<1:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings-python-legacy>0:textproc/py-mkdocstrings-python-legacy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.9.0<1:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=10.0.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg>=3.1.10<4:databases/py-psycopg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}requests>=2.31.0<3:www/py-requests@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.21.1<2:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-app-django>=5.4.0<6:www/py-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.4.2<5:security/py-social-auth-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.3<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.5.0<4:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2023.3:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=6.0<7:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=21.2.0<22:www/py-gunicorn@${PY_FLAVOR}

USES=		cpe pgsql:12+ python
CPE_VENDOR=	netbox_project
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	850.netbox-housekeeping.sample netbox_rq.sample netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES
OPTIONS_GROUP=	BACKENDS
OPTIONS_GROUP_BACKENDS=	GIT LDAP S3

GIT_DESC=	Git backend support
LDAP_DESC=	LDAP backend support
S3_DESC=	Amazon S3 backend support

GIT_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dulwich>0:devel/py-dulwich@${PY_FLAVOR}
LDAP_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dj42-django-auth-ldap>0:www/py-dj42-django-auth-ldap
S3_RUN_DEPENDS=		${PYTHON_PKGNAMEPREFIX}boto3>0:www/py-boto3@${PY_FLAVOR}

do-install:
	cd ${WRKSRC}/netbox ; \
	for src in $$( ${FIND} . ! -name '*.bak' ) ; do \
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
