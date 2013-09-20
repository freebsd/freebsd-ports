# Created by: Alexander Leidinger
# $FreeBSD$

PORTNAME=		soappy
PORTVERSION=		0.12.0
CATEGORIES=		net python
MASTER_SITES=		SF/pywebsvcs/SOAP.py/${PORTVERSION}_rc1
PKGNAMEPREFIX=		${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=		-devel
DISTNAME=		SOAPpy-${PORTVERSION}

MAINTAINER=		ports@FreeBSD.org
COMMENT=		A SOAP implementation

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	SOAPpy

BUILD_DEPENDS+=		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
RUN_DEPENDS+=		${PYXML} \
			${BUILD_DEPENDS}

CONFLICTS=		py*-soappy-0.11.*

.if !defined(NOPORTDOCS)
PORTDOCS=		*
.endif

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	@${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCSDIR}
.endif
	@${MKDIR} ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/contrib/* ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/tools/* ${DATADIR}
	@${INSTALL_DATA} ${WRKSRC}/validate/* ${DATADIR}

.include <bsd.port.mk>
