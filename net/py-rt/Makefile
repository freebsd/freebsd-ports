# ex:ts=8
# Ports collection makefile for:	py-rt
# Date created:			Jun 14, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	rt
PORTVERSION=	2.5
CATEGORIES=	net python
MASTER_SITES=	http://research.sprintlabs.com/pyrt/results/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyrt-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python Routeing Toolkit

USE_PYTHON=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
DOCSDIR=	${PREFIX}/share/doc/py-rt

post-patch:
.for file in bgp.py isis.py
	@${REINPLACE_CMD} -e "s/python2/python/g" ${WRKSRC}/${file}
.endfor

do-install:
	${MKDIR} ${PYTHON_SITELIBDIR}/rt
	(cd ${WRKSRC} ; ${INSTALL_SCRIPT} *.py ${PYTHON_SITELIBDIR}/rt)
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} ; ${INSTALL_SCRIPT} README* ${DOCSDIR})
.endif

.include <bsd.port.mk>
