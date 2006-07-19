# New ports collection makefile for:   myghty
# Date created:                July 13 2005
# Whom:                        Dryice Liu <dryice@liu.com.cn>
#
# $FreeBSD$
#

PORTNAME=	myghty
PORTVERSION=	1.0.1
CATEGORIES=	www python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
DISTNAME=	Myghty-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A Python based templating framework

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools

USE_PYTHON=	2.3+
NO_BUILD=	yes
PLIST_SUB=	VERSION="${PORTVERSION}" PYVER="${PYTHON_VERSION:S/python//}"

do-install:
	cd ${BUILD_WRKSRC} \
		&& ${PYTHON_CMD} setup.py install --old-and-unmanageable

.include <bsd.port.mk>
