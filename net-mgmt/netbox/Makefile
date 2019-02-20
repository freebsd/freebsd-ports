# $FreeBSD$

PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.5.6
CATEGORIES=	net-mgmt

MAINTAINER=	kai@FreeBSD.org
COMMENT=	IP address management tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django21>=2.1.5:www/py-django21@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-cors-headers>=2.4.0:www/py-dj21-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-debug-toolbar>=1.11:www/py-dj21-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-filter>=2.0.0:www/py-dj21-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-mptt>=0.9.1:www/py-dj21-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-tables2>=2.0.3:www/py-dj21-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-taggit>=0.23.0:www/py-dj21-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-taggit-serializer>=0.1.7:www/py-dj21-django-taggit-serializer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-django-timezone-field>=3.0:www/py-dj21-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-djangorestframework>=3.9.0:www/py-dj21-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}dj21-drf-yasg>=1.11.1:www/py-dj21-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gfm>=0.1.4:textproc/py-gfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>=0.10.1:graphics/py-graphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.11:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.19:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.7.2:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.3.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.6.1:databases/py-psycopg2@${PY_FLAVOR}

USES=		pgsql:9.4+ python:3.5+
USE_GITHUB=	yes
GH_ACCOUNT=	digitalocean

SUB_FILES=	pkg-message
SUB_LIST=	DATADIR=${DATADIR} PYTHON_VER=${PYTHON_VER}
NO_BUILD=	yes
NO_ARCH=	yes

OPTIONS_DEFINE=	DOCS

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

.include <bsd.port.mk>
