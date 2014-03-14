# Created by: Nicola Vitale <nivit@FreeBSD.org>
# $FreeBSD$

PORTNAME=	pylot
PORTVERSION=	1.26
PORTREVISION=	4
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}
DISTNAME=	${PORTNAME}_${PORTVERSION}

MAINTAINER=	nivit@FreeBSD.org
COMMENT=	Tool for testing performance and scalability of web services

OPTIONS_DEFINE=	GUI REPORTGRAPHS
OPTIONS_DEFAULT=	REPORTGRAPHS
GUI_DESC=		Enable GUI mode
REPORTGRAPHS_DESC=	Enable report graphs

PROJECTHOST=	pylt

DATADIR=	${PREFIX}/share/${PYTHON_PKGNAMEPREFIX}${PORTNAME}

NO_BUILD=	yes

SUB_FILES=	${PORTNAME}
SUB_LIST=	PYTHON_CMD=${PYTHON_CMD}

USES=		zip
USE_PYTHON=	yes

NO_STAGE=	yes
do-install:
	@${MKDIR} ${DATADIR} && cd ${WRKSRC} && ${COPYTREE_SHARE} . ${DATADIR}
	@${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${PREFIX}/bin/${PORTNAME}

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_WX=	2.4+
WX_COMPS=	python:run
.endif

.if ${PORT_OPTIONS:MREPORTGRAPHS}
RUN_DEPENDS+=	${PYNUMPY}
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/matplotlib/__init__.py:${PORTSDIR}/math/py-matplotlib
.endif

.include <bsd.port.mk>
