# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	TVGrab
PORTVERSION=	0.5.1
PORTREVISION=	3
CATEGORIES=	textproc python
MASTER_SITES=	SF/py${PORTNAME:L}/lib/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pytvgrab-lib-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to write grabbers of tv scheduling collections

EXTRACT_DEPENDS=	${PYTHON_PKGNAMEPREFIX}dateutil>=1.4:${PORTSDIR}/devel/py-dateutil:extract

USE_BZIP2=		yes
USE_PYTHON=		2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

PORTDOCS=	README

post-extract:
	@${CP} ${FILESDIR}/timezone.py ${WRKSRC}/lib/timezone.py

post-patch:
	@${REINPLACE_CMD} -e 's,python -c,${PYTHON_CMD} -c,' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
