# New ports collection makefile for:	py-turbomail
# Date created:		2007-01-24
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	turbomail
PORTVERSION=	2.0.3
CATEGORIES=	mail www
MASTER_SITES=	http://cheeseshop.python.org/packages/source/T/TurboMail/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	TurboMail-${PORTVERSION}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Multi-threaded mail queue manager for TurboGears applications

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		tg-admin:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS=	${BUILD_DEPENDS}

PLIST_FILES=	${PYTHON_SITELIBDIR:S|${PREFIX}/||}/${PYTURBOMAIL_EGG}

SUB_FILES=	pkg-deinstall pkg-install
SUB_LIST=	PYTHON_SITELIBDIR=${PYTHON_SITELIBDIR} \
		EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		EGG_VER="${PORTNAME}==${PORTVERSION}"

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYTURBOMAIL_EGG=	TurboMail-${PORTVERSION}-py${PYTHON_VER}.egg

.include <bsd.port.mk>
