# New ports collection makefile for:	py-scientific
# Date created:		29 July 1999
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	scientific
PORTVERSION=	2.4
CATEGORIES=	math python
MASTER_SITES=	http://starship.python.net/crew/hinsen/ \
		http://dirac.cnrs-orleans.fr/programs/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ScientificPython-${PORTVERSION}

MAINTAINER=	tg@FreeBSD.org

BUILD_DEPENDS=	${PYNUMERIC}
LIB_DEPENDS=	netcdf.1:${PORTSDIR}/math/netcdf
RUN_DEPENDS=	${PYNUMERIC}

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

DOCDIR=		${PREFIX}/share/doc/py-scientific
EXAMPLEDIR=	${PREFIX}/share/examples/py-scientific

post-install:
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/LICENSE ${DOCDIR}
.if !defined(NOPORTDOCS)
	cd ${WRKDIR}/${DISTNAME}/Doc; tar -c --exclude='*~' -f - . | \
	    (cd ${DOCDIR}; tar -xf -)
	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKDIR}/${DISTNAME}/Examples; tar -c --exclude='*~' -f - . | \
	    (cd ${EXAMPLEDIR}; tar -xf -)
.endif

.include <bsd.port.mk>
