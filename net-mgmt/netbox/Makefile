# $FreeBSD$

PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.6.8
PORTREVISION=	1
CATEGORIES=	net-mgmt

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django22>=2.2<2.3:www/py-django22@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-cacheops>=4.1:www/py-dj22-django-cacheops@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-cors-headers>=3.0.2:www/py-dj22-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-debug-toolbar>=2.0:www/py-dj22-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-filter>=2.1.0:www/py-dj22-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-mptt>=0.9.1:www/py-dj22-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-prometheus>=1.0.15:www/py-dj22-django-prometheus@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-rq>=2.1.0:devel/py-dj22-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-tables2>=2.0.6:www/py-dj22-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-taggit>=0:www/py-dj22-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-taggit-serializer>=0.1.7:www/py-dj22-django-taggit-serializer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-django-timezone-field>=3.0:www/py-dj22-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-djangorestframework>=3.9.4:www/py-dj22-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj22-drf-yasg>=1.16.0:www/py-dj22-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gfm>=0.1.4:textproc/py-gfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>=0.10.1:graphics/py-graphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}Jinja2>=2.10.1:devel/py-Jinja2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.11:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.19:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.8.2:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=6.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.8.3:databases/py-psycopg2@${PY_FLAVOR}

USES=		pgsql:9.4+ python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	netbox-community

SUB_FILES=	netboxrc.sample pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_CMD=${PYTHON_CMD} PYTHON_VER=${PYTHON_VER} WWWOWN=${WWWOWN}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS EXAMPLES

post-patch:
	@${REINPLACE_CMD} -e 's|==|>=|' ${WRKSRC}/requirements.txt

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
