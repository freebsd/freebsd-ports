# ex:ts=8
# Ports collection makefile for:	flyway
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flyway
PORTVERSION=	0.3.1
CATEGORIES=	misc python
MASTER_SITES=	http://www.bellz.org/flyway/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A VFR/IFR Route Planner for Pilots

RUN_DEPENDS=	pyuic:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
NO_BUILD=	yes
WRKSRC=		${WRKDIR}/FlyWay

do-install:
	@${MKDIR} ${PYTHON_SITELIBDIR}/${PORTNAME}
	${CP} ${WRKSRC}/*.py ${PYTHON_SITELIBDIR}/${PORTNAME}
	${CP} ${WRKSRC}/*.dat ${PYTHON_SITELIBDIR}/${PORTNAME}
	@${LN} -sf ${PYTHON_SITELIBDIR}/${PORTNAME}/flyway.py ${PREFIX}/bin/flyway
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/README.html ${DOCSDIR}
.endif

.include <bsd.port.mk>
