# $FreeBSD$

PORTNAME=	reviewboard
PORTVERSION=	2.5.1.1
PORTREVISION=	1
CATEGORIES=	www devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/ReviewBoard/${PORTVERSION:R:R}/
DISTNAME=	ReviewBoard-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Web-based code review tool

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

BROKEN=		depends on conflicting versions of django

RUN_DEPENDS=	python:lang/python \
		${PYTHON_PKGNAMEPREFIX}django16>=1.6.11:www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.7:www/py-django-evolution \
		${PYTHON_PKGNAMEPREFIX}django-pipeline13>=1.3.27:www/py-django-pipeline13 \
		${PYTHON_PKGNAMEPREFIX}djblets>=0.7.9:www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}docutils>0:textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}django-haystack>=2.4.1:www/py-django-haystack \
		${PYTHON_PKGNAMEPREFIX}flup>0:www/py-flup \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}python-memcached>0:databases/py-python-memcached \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.3:devel/py-mimeparse \
		${PYTHON_PKGNAMEPREFIX}paramiko>=1.9.0:security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pytz>0:devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}recaptcha>0:www/py-recaptcha \
		${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.3:devel/py-mimeparse
BUILD_DEPENDS=	python:lang/python \
		${PYTHON_PKGNAMEPREFIX}django16>=1.6.7:www/py-django16 \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.7:www/py-django-evolution \
		${PYTHON_PKGNAMEPREFIX}djblets>=0.7.7:www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}django-haystack>=2.4.1:www/py-django-haystack \
		${PYTHON_PKGNAMEPREFIX}futures>=0:devel/py-futures \
		${PYTHON_PKGNAMEPREFIX}jsmin>0:devel/py-jsmin \
		uglifyjs:www/uglifyjs

USES=		cpe gettext-tools python:2
CPE_VENDOR=	reviewboard
CPE_PRODUCT=	review_board
USE_PYTHON=	distutils
PYDISTUTILS_PKGNAME=	ReviewBoard
# avoid leftover /root/.subversion
MAKE_ENV+=		HOME=${WRKDIR}

OPTIONS_DEFINE=	SVN
OPTIONS_DEFAULT=	SVN

SVN_DESC=	Support reviews for SVN repository

SVN_RUN_DEPENDS=	pysvn>0:devel/pysvn

post-patch:
	@${REINPLACE_CMD} -e  "s|TIME_ZONE = 'UTC'|TIME_ZONE = 'Etc/UTC'|" ${WRKSRC}/reviewboard/settings.py
	@${REINPLACE_CMD} -e 's|python-dateutil==1.5|python-dateutil|' ${WRKSRC}/setup.py
	@${FIND} ${WRKSRC} -name '*.bak' -delete

.include <bsd.port.mk>
