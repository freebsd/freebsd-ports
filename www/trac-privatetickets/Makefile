# New ports collection makefile for:	trac-privatetickets
# Date created:		Feb. 20, 2007
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	privatetickets
PORTVERSION=	1.1
CATEGORIES=	www devel python
MASTER_SITES=	http://cheeseshop.python.org/packages/source/T/TracPrivateTickets/
PKGNAMEPREFIX=	trac-
DISTNAME=	TracPrivateTickets-${PORTVERSION}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Modified ticket security for Trac

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tracd:${PORTSDIR}/www/trac

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-O 1 -N -S ${PYTHON_SITELIBDIR} ${WRKSRC}/dist/${TRACPRIVATETICKETS_EGG}

TRACPRIVATETICKETS_EGG=	TracPrivateTickets-${PORTVERSION}-py${PYTHON_VER}.egg

PLIST_SUB+=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		TRACPRIVATETICKETS_EGG=${TRACPRIVATETICKETS_EGG} \
		TRACPRIVATETICKETS_EGG_VER="TracPrivateTickets==${PORTVERSION}"

.include <bsd.port.mk>
