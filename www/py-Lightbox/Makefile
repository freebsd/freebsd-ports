# New ports collection makefile for:	py-Lightbox
# Date created:		2007-02-14
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Lightbox
PORTVERSION=	2.0.p1
CATEGORIES=	www python
MASTER_SITES=	http://files.turbogears.org/eggs/ \
		http://nivi.interfree.it/distfiles/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.p/_p/}-py${PYTHON_VER}.egg
EXTRACT_SUFX=

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Lightbox photo display widget for TurboGears

BUILD_DEPENDS=	${EASY_INSTALL_CMD}:${PORTSDIR}/devel/py-setuptools \
		${PYTHON_PKGNAMEPREFIX}TurboGears>=1.0.1:${PORTSDIR}/www/py-turbogears
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	2.4

PLIST_SUB=	EASY_INSTALL_CMD=${EASY_INSTALL_CMD} \
		PORTNAME=${PORTNAME} PORTVERSION=${PORTVERSION:S/.p/_p/} \
		PYLIGHTBOX_EGG=${PYLIGHTBOX_EGG}

EASY_INSTALL_CMD?=	easy_install-${PYTHON_VER}
PYLIGHTBOX_EGG=	${DISTNAME}

do-build:
	@${DO_NADA}

do-install:
	@${EASY_INSTALL_CMD} -N ${DISTDIR}/${PYLIGHTBOX_EGG}

.include <bsd.port.mk>
