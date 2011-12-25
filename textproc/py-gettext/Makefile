# New ports collection makefile for:	py-gettext
# Date created:				Nov 11, 2011
# Whom:					Ruslan Mahmatkhanov <cvs-src@yandex.ru>
#
# $FreeBSD$
#

PORTNAME=	gettext
PORTVERSION=	2.0
CATEGORIES=	textproc python
MASTER_SITES=	CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	python-${PORTNAME}-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	Python Gettext po to mo file compiler

LICENSE=	BSD

# Python3 and Pypy 1.7 ready
USE_PYTHON=		yes
USE_PYDISTUTILS=	easy_install
PYDISTUTILS_PKGNAME=	python-${PORTNAME}
USE_ZIP=		yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} <= 300
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}unittest2>=0:${PORTSDIR}/devel/py-unittest2
.endif

.include <bsd.port.post.mk>
