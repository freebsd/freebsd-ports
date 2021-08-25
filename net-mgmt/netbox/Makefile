PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.11.12
CATEGORIES=	net-mgmt

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
# - devel/py-dj32-django-rq
# - www/py-dj32-django-filter
# - www/py-dj32-django-tables2
# - www/py-dj32-djangorestframework (in conjunction with www/py-dj32-drf-yasg)
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django32>=3.2.6<3.3:www/py-django32@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-cacheops>=6.0<7.0:www/py-dj32-django-cacheops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-cors-headers>=3.8.0<3.9:www/py-dj32-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-debug-toolbar>=3.2.1<4:www/py-dj32-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-filter>=2.4.0<2.5:www/py-dj32-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-mptt>=0.13.1<0.14:www/py-dj32-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-prometheus>=2.1.0<2.2:www/py-dj32-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-rq>=2.4.1<2.5:devel/py-dj32-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-tables2>=2.4.0<2.5:www/py-dj32-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-taggit>=1.5.1<2:www/py-dj32-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-django-timezone-field>=4.1.2<5:www/py-dj32-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-djangorestframework>=3.12.4<3.13.0:www/py-dj32-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj32-drf-yasg>=1.20.0<1.21:www/py-dj32-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.2<4:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=3.3.4<3.5:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.8.0<1:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.10.1<4:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=8.2.0<9:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.9.1<3:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4.1<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}tablib>=3.0.0<3.1:textproc/py-tablib@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.4.1<6:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=19.9.0<21:www/py-gunicorn@${PY_FLAVOR}

USES=		pgsql:9.6+ python:3.7+
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	netbox_rq.sample netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

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

post-install-DOCS-on:
	cd ${WRKSRC}/docs ; \
	${MKDIR} ${STAGEDIR}${DOCSDIR} ; \
	for src in $$( ${FIND} . ! -name '*.bak' ) ; do \
		dst=${STAGEDIR}${DOCSDIR}$${src#.} ; \
		if ${TEST} -d "$$src" ; then \
			${MKDIR} "$$dst" ; \
		else \
			${INSTALL_DATA} "$$src" "$$dst" ; \
		fi \
	done

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netbox_rq.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKDIR}/netboxrc.sample ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/apache.conf ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/gunicorn.py ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/nginx.conf ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
