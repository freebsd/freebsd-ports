# ex:ts=8
# Ports collection makefile for:	flyway
# Date created:			Mar 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	flyway
PORTVERSION=	0.2.2
CATEGORIES=	misc python
MASTER_SITES=	http://www.bellz.org/flyway/

MAINTAINER=	kde@freebsd.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/qt.py:${PORTSDIR}/x11-toolkits/py-qt

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes

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
