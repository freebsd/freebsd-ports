# $FreeBSD$

PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.10.6
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
# - devel/py-dj31-django-rq
# - www/py-dj31-django-filter
# - www/py-dj31-django-tables2
# - www/py-dj31-djangorestframework (in conjunction with www/py-dj31-drf-yasg)
#
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django31>=3.1.3<3.2:www/py-django31@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-cacheops>=5.1.0<5.2:www/py-dj31-django-cacheops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-cors-headers>=3.5.0<3.8:www/py-dj31-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-debug-toolbar>=3.1.1<4:www/py-dj31-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-filter>=2.4.0<2.5:www/py-dj31-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-mptt>=0.11.0<0.13:www/py-dj31-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-prometheus>=2.1.0<2.2:www/py-dj31-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-rq>=2.4.0<2.5:devel/py-dj31-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-tables2>=2.3.3<2.4:www/py-dj31-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-taggit>=1.3.0<2:www/py-dj31-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-django-timezone-field>=4.0<5:www/py-dj31-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-djangorestframework>=3.12.2<3.13.0:www/py-dj31-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj31-drf-yasg>=1.20.0<1.21:www/py-dj31-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4<1.1:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.11.2<3:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.11<3.5:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.19<1:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.9.8<4:security/py-pycryptodome@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.6<3:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.4<2:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.3.1<6:devel/py-yaml@${PY_FLAVOR} \
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
