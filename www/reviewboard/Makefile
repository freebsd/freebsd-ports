# New ports collection makefile for:	reviewboard
# Date created:		2011-02-26
# Whom:			Li-Wen Hsu <lwhsu@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reviewboard
PORTVERSION=	1.6.11
CATEGORIES=	www devel
MASTER_SITES=	http://downloads.reviewboard.org/releases/ReviewBoard/${PORTVERSION:R}/
DISTNAME=	ReviewBoard-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	A web-based code review tool

LICENSE=	MIT

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}django>=1.3.2<1.4:${PORTSDIR}/www/py-django13 \
		${PYTHON_PKGNAMEPREFIX}django-evolution>=0.6.5:${PORTSDIR}/www/py-django-evolution \
 		${PYTHON_PKGNAMEPREFIX}djblets>=0.6.22:${PORTSDIR}/www/py-djblets \
		${PYTHON_PKGNAMEPREFIX}pygments>=1.4:${PORTSDIR}/textproc/py-pygments \
		${PYTHON_PKGNAMEPREFIX}flup>0:${PORTSDIR}/www/py-flup \
		${PYTHON_PKGNAMEPREFIX}paramiko>1.7.6:${PORTSDIR}/security/py-paramiko \
		${PYTHON_PKGNAMEPREFIX}dateutil>0:${PORTSDIR}/devel/py-dateutil \
		${PYTHON_PKGNAMEPREFIX}memcached>0:${PORTSDIR}/databases/py-memcached \
		${PYTHON_PKGNAMEPREFIX}pytz>0:${PORTSDIR}/devel/py-pytz \
		${PYTHON_PKGNAMEPREFIX}recaptcha>0:${PORTSDIR}/www/py-recaptcha

USE_PYTHON=	yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	ReviewBoard

.include <bsd.port.mk>
