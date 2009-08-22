# New ports collection makefile for:	py-turbodjango
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	turbodjango
PORTVERSION=	0.95.w2
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	SF/tgwidgets/TurboDjango/TurboDjango%200.95w2
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PYTURBODJANGO_EGG}
EXTRACT_SUFX=

MAINTAINER=	python@FreeBSD.org
COMMENT=	Django template for TurboGears

RUN_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}django>=0.95_2:${PORTSDIR}/www/py-django \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears

NO_BUILD=	yes

USE_PYTHON=	yes

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

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 240 || ${PYTHON_REL} >= 250
IGNORE=	the distribution file is available only for Python 2.4
.endif

.include <bsd.port.post.mk>
