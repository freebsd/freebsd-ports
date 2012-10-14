# $FreeBSD$

PORTNAME=	reviewboard
PORTVERSION=	1.6.13
CATEGORIES=	www devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/ReviewBoard/${PORTVERSION:R}/
DISTNAME=	ReviewBoard-${PORTVERSION}

MAINTAINER=	linpc@cs.nctu.edu.tw
COMMENT=	A web-based code review tool

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3.3<1.4:${PORTSDIR}/www/py-django13 \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.5:${PORTSDIR}/www/py-django-evolution \
 		${PYTHON_PKGNAMEPREFIX}djblets>=0.6.23:${PORTSDIR}/www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}paramiko>1.7.6:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}dateutil>=1.5:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}memcached>0:${PORTSDIR}/databases/py-memcached \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	ReviewBoard

.include <bsd.port.mk>
