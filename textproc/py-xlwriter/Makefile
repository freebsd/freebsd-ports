# Created by: Choe, Cheng-Dae
# $FreeBSD$

PORTNAME=	xlwriter
PORTVERSION=	0.4a3
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyXLWriter-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Python library for generating Excel-compatible spreadsheets

USES=		zip
USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTEXAMPLES=	*

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} {} ${STAGEDIR}${EXAMPLESDIR} \;

.include <bsd.port.mk>
