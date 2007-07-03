# Ports collection makefile for:	pssh
# Date created:				Mon Jul 2, 2007
# Whom:					Brooks Davis <brooks@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pssh
PORTVERSION=	1.3.1
CATEGORIES=	security net sysutils
MASTER_SITES=	http://www.theether.org/pssh/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	brooks

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	Parallel versions of the openssh tools

BUILD_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools
RUN_DEPENDS=	easy_install:${PORTSDIR}/devel/py-setuptools \
		rsync:${PORTSDIR}/net/rsync

USE_PYTHON=	YES
USE_PYDISTUTILS=yes

PLIST_SUB+=	PSSH_EGG=${PSSH_EGG} \
		EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PSSH_EGG=${PSSH_EGG} \
		EGG="pssh==${PORTVERSION}"

PYDISTUTILS_BUILD_TARGET=	bdist_egg
PYDISTUTILS_INSTALL_TARGET=	easy_install
PYDISTUTILS_INSTALLARGS=	-N -O1 -s ${PREFIX}/bin -S ${PYTHON_SITELIBDIR} dist/${PSSH_EGG}

EASY_INSTALL_CMD=	easy_install-${PYTHON_VER}
PSSH_EGG=	${PORTNAME}-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
