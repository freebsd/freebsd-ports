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
COMMENT=		SOAP implementation

BUILD_DEPENDS=		${PYTHON_SITELIBDIR}/fpconst.py:${PORTSDIR}/math/py-fpconst
RUN_DEPENDS:=		${PYXML} \
			${BUILD_DEPENDS}

USES=		python
USE_PYTHON=	distutils autoplist

CONFLICTS=		py*-soappy-0.11.*

PORTDOCS=		*
PORTDATA=		*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${STAGEDIR}${DOCSDIR}
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/contrib/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/tools/* ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/validate/* ${STAGEDIR}${DATADIR}

.include <bsd.port.mk>
