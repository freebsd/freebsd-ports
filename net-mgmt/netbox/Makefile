PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	3.2.6
CATEGORIES=	net-mgmt python

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

# NetBox has fixed Python package dependencies listed in "requirements.txt"
# which are not checked during build/runtime because they're usually installed
# via devel/py-pip.
#
# As a rule, slight deviations are usally not a problem, but there are a few
# Django packages that are known for regressions in conjunction with NetBox and
# should therefore only be updated with caution.
#
# - devel/py-dj40-django-rq
# - www/py-dj40-django-filter
# - www/py-dj40-django-tables2
# - www/py-dj40-djangorestframework (in conjunction with www/py-dj40-drf-yasg)
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django40>=4.0.6<4.1:www/py-django40@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-cors-headers>=3.13.0<4:www/py-dj40-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-debug-toolbar>=3.5.0<4:www/py-dj40-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-filter>=22.1<23:www/py-dj40-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-graphiql-debug-toolbar>=0.2.0<1:www/py-dj40-django-graphiql-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-mptt>=0.13.4<0.14:www/py-dj40-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-prometheus>=2.2.0<2.3:www/py-dj40-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-redis>=5.2.0<6:www/py-dj40-django-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-rq>=2.5.1<2.6:devel/py-dj40-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-tables2>=2.4.1<2.5:www/py-dj40-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-taggit>=2.1.0<3:www/py-dj40-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-django-timezone-field>=5.0<6:www/py-dj40-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-djangorestframework>=3.13.1<3.14.0:www/py-dj40-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-drf-yasg>=1.20.0<1.21:www/py-dj40-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj40-graphene-django>=2.15.0<3:devel/py-dj40-graphene-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}bleach>=5.0.1<6:www/py-bleach@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=3.0.1<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.7<3.5:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown-include>=0.6.0<1:textproc/py-markdown-include@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocs-material>=8.2.11<9:textproc/py-mkdocs-material@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}mkdocstrings>=0.17.0<1:textproc/py-mkdocstrings@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.8.0<1:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=9.1.1:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.3<3:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}sentry-sdk>=1.5.12<2:devel/py-sentry-sdk@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-app-django>=5.0.0<6:www/py-social-auth-app-django@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}social-auth-core>=4.2.0<5:security/py-social-auth-core@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.2<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.2.1<4:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tzdata>=2022.1:devel/py-tzdata@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.4.1<7:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=20.1.0<21:www/py-gunicorn@${PY_FLAVOR}

USES=		cpe pgsql:10+ python:3.8+
CPE_VENDOR=	netbox_project
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	850.netbox-housekeeping.sample netbox_rq.sample netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	EXAMPLES

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
