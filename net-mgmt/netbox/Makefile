# $FreeBSD$

PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.7.9
CATEGORIES=	net-mgmt

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2<2.3:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-cacheops>=4.2:www/py-dj22-django-cacheops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-cors-headers>=3.2.1:www/py-dj22-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-debug-toolbar>=2.1:www/py-dj22-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-filter>=2.2.0:www/py-dj22-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-mptt>=0.9.1:www/py-dj22-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-prometheus>=1.1.0:www/py-dj22-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-rq>=2.2.0:devel/py-dj22-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-tables2>=2.2.1:www/py-dj22-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-taggit>=1.2.0:www/py-dj22-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-taggit-serializer>=0.1.7:www/py-dj22-django-taggit-serializer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-timezone-field>=4.0:www/py-dj22-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-djangorestframework>=3.10.3:www/py-dj22-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-drf-yasg>=1.17.0:www/py-dj22-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-pglocks>=1.0.4:www/py-django-pglocks@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gfm>=0.1.4:textproc/py-gfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.11:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.19:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.8.2:security/py-pycryptodome@${PY_FLAVOR} \
		${PY_PILLOW} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.4:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}redis>=3.3.11:databases/py-redis@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}svgwrite>=1.3.1:graphics/py-svgwrite@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}yaml>=5.2:devel/py-yaml@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gunicorn>=19.9.0.:www/py-gunicorn@${PY_FLAVOR}

USES=		pgsql:9.4+ python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	netboxrc.sample pkg-message
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
	${INSTALL_DATA} ${WRKDIR}/netboxrc.sample ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
