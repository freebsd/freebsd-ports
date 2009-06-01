# New ports collection makefile for:	pylot
# Date created:		2009-06-01
# Whom:			Nicola Vitale <nivit@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	pylot
PORTVERSION=	1.24
#PORTREVISION=	0
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for testing performance and scalability of web services

OPTIONS=	GUI	"Enable GUI mode" off \
		REPORTGRAPHS "Enable report graphs" on

PROJECTHOST=	pylt

DATADIR=	${PREFIX}/share/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USE_PYTHON=	2.5+
USE_ZIP=	yes

do-install:
	@${MKDIR} ${DATADIR} && cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.pre.mk>

.if defined(WITH_GUI)
USE_WX=	2.4+
WX_COMPS=	python:run
.endif

.if defined(WITH_REPORTGRAPHS)
RUN_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib
.endif

.include <bsd.port.post.mk>
