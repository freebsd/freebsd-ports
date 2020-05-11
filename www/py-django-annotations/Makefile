# $FreeBSD$

PORTNAME=	django-annotations
PORTVERSION=	0.0.0.2016041401
PORTREVISION=	4
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Django implementation of annotatorjs Storage

LICENSE=	APACHE20

DEPRECATED=	No longer maintained, not compatible with Django 2.0+
EXPIRATION_DATE=	2020-05-25

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django-cors-headers>=1.1.0:www/py-django-cors-headers@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}djangorestframework>=3.3.2:www/py-djangorestframework@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-rq>0:devel/py-django-rq@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}django-rq-dashboard>0:devel/py-django-rq-dashboard@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz@${PY_FLAVOR}

USES=		python
USE_GITHUB=	yes
USE_PYTHON=	autoplist concurrent distutils

GH_ACCOUNT=	TheDataShed
GH_TAGNAME=	cdb04b4

NO_ARCH=	yes
PLIST_FILES=	"@sample etc/annotations/default/__init__.py.sample"

.include <bsd.port.pre.mk>

post-extract:
	@${MV} ${WRKSRC}/manage.py ${WRKSRC}/annotations.py
	@${MV} ${WRKSRC}/templates ${WRKSRC}/annotation

post-patch:
	@${REINPLACE_CMD} -i '' -e 's|%%PREFIX%%|${PREFIX}|' \
		${WRKSRC}/annotations.py

post-install:
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/annotations/default
	${INSTALL_DATA} ${WRKSRC}/annotator/settings/base.py ${STAGEDIR}${PREFIX}/etc/annotations/default/__init__.py.sample

.include <bsd.port.post.mk>
