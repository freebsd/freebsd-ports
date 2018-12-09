# $FreeBSD$

PORTNAME=	netbox
DISTVERSIONPREFIX=	v
DISTVERSION=	2.4.9
CATEGORIES=	net-mgmt

MAINTAINER=	freebsd_ports@k-worx.org
COMMENT=	IP address management tool

LICENSE=	APACHE20
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django111>=1.11:www/py-django111@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-cors-headers>=2.4.0:www/py-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-debug-toolbar>=1.9.1:www/py-django-debug-toolbar@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-filter>=1.1.0:www/py-django-filter@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-mptt>=0.9.1:www/py-django-mptt@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-tables2>=1.21.2:www/py-django-tables2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit>=0.22.2:www/py-django-taggit@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-taggit-serializer>=0.1.7:www/py-django-taggit-serializer@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-timezone-field>=2.1:www/py-django-timezone-field@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.8.1:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}drf-yasg>=1.9.2:www/py-drf-yasg@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}gfm>=0.1.3:textproc/py-gfm@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}graphviz>=0.8.4:graphics/py-graphviz@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.6.11:textproc/py-markdown@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}ncclient>=0.6.0:net-mgmt/py-ncclient@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}netaddr>=0.7.19:net/py-netaddr@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}paramiko>=2.4.2:security/py-paramiko@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pycryptodome>=3.6.6:security/py-pycryptodome@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pillow>=5.2.0:graphics/py-pillow@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}psycopg2>=2.7.5:databases/py-psycopg2@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}natsort>=5.3.3:devel/py-natsort@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}xmltodict>=0.11.0:devel/py-xmltodict@${PY_FLAVOR}

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
