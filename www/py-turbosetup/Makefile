# New ports collection makefile for:	py-turbosetup
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	turbosetup
PORTVERSION=	0.2
CATEGORIES=	www python
MASTER_SITES=	http://cheeseshop.python.org/packages/2.3/T/${PYTURBOSETUP}/ \
		http://nivi.interfree.it/distfiles/${PYTURBOSETUP}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBOSETUP_EGG}
EXTRACT_SUFX=

MAINTAINER=	python@FreeBSD.org
COMMENT=	A web based configuration environment for TurboGears

RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears

NO_BUILD=	yes

# Use the same version of www/py-turbogears
USE_PYTHON=	2.4

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYTURBOSETUP_EGG=${PYTURBOSETUP_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
EASY_INSTALL_ARGS=	-N

PYTURBOSETUP=	TurboSetup
PYTURBOSETUP_EGG=	${PYTURBOSETUP}-${PORTVERSION}-py${PYTHON_VER}.egg

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}

do-install:
	@${EASY_INSTALL_CMD} ${EASY_INSTALL_ARGS} ${DISTDIR}/${PYTURBOSETUP_EGG}

.include <bsd.port.mk>
