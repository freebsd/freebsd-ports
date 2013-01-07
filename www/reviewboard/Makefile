# $FreeBSD$

PORTNAME=	reviewboard
PORTVERSION=	1.7.1
CATEGORIES=	www devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/ReviewBoard/${PORTVERSION:R}/
DISTNAME=	ReviewBoard-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	Web-based code review tool

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4.3<1.5:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.7:${PORTSDIR}/www/py-django-evolution \
		${PYTHON_PKGNAMEPREFIX}django-pipeline>=1.2.22:${PORTSDIR}/www/py-django-pipeline \
		${PYTHON_PKGNAMEPREFIX}djblets>=0.7.7:${PORTSDIR}/www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}docutils>0:${PORTSDIR}/textproc/py-docutils \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}dateutil==1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}markdown>=2.2.1:${PORTSDIR}/textproc/py-markdown \
		${PYTHON_PKGNAMEPREFIX}memcached>0:${PORTSDIR}/databases/py-memcached \
		${PYTHON_PKGNAMEPREFIX}mimeparse>=0.1.3:${PORTSDIR}/devel/py-mimeparse \
		${PYTHON_PKGNAMEPREFIX}paramiko>=1.9.0:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.5:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}recaptcha>0:${PORTSDIR}/www/py-recaptcha
BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.4.3<1.5:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.7:${PORTSDIR}/www/py-django-evolution \
		${PYTHON_PKGNAMEPREFIX}djblets>=0.7.7:${PORTSDIR}/www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}jsmin>0:${PORTSDIR}/devel/py-jsmin

USE_PYTHON=	-2.7
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	ReviewBoard

.include <bsd.port.mk>
