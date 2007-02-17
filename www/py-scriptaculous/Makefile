# New ports collection makefile for:	py-scriptaculous
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scriptaculous
PORTVERSION=	1.6.2
CATEGORIES=	www python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYSCRIPTACULOUS_EGG}
EXTRACT_SUFX=

MAINTAINER=	python@FreeBSD.org
COMMENT=	Scriptaculous packaged as TurboGears widgets

RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears

NO_BUILD=	yes

# Use the same version of www/py-turbogears
USE_PYTHON=	2.4

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION} \
		PYSCRIPTACULOUS_EGG=${PYSCRIPTACULOUS_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
EASY_INSTALL_ARGS=	-N

PYSCRIPTACULOUS_EGG=	${PORTNAME:S/^s/S/}-${PORTVERSION}-py${PYTHON_VER}.egg

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}

do-install:
	@${EASY_INSTALL_CMD} ${EASY_INSTALL_ARGS} ${DISTDIR}/${PYSCRIPTACULOUS_EGG}

.include <bsd.port.mk>
