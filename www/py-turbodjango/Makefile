# New ports collection makefile for:	py-turbodjango
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	turbodjango
PORTVERSION=	0.95.w2
CATEGORIES=	www python
MASTER_SITES=	SF
MASTER_SITE_SUBDIR=	tgwidgets
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBODJANGO_EGG}
EXTRACT_SUFX=

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django template for TurboGears

RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}django>=0.95_2:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears

NO_BUILD=	yes

# Use the same version of www/py-turbogears
USE_PYTHON=	2.4

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PYTURBODJANGO_VER} \
		PYTURBODJANGO_EGG=${PYTURBODJANGO_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
EASY_INSTALL_ARGS=	-N

PYTURBODJANGO=	TurboDjango
PYTURBODJANGO_VER=	${PORTVERSION:C/([0-9])\.([a-z])/\1\2/}
PYTURBODJANGO_EGG=	${PYTURBODJANGO}-${PYTURBODJANGO_VER}-py${PYTHON_VER}.egg

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}

do-install:
	@${EASY_INSTALL_CMD} ${EASY_INSTALL_ARGS} ${DISTDIR}/${PYTURBODJANGO_EGG}

.include <bsd.port.mk>
