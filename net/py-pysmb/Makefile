# Created by: ijliao
# $FreeBSD$

PORTNAME=	pysmb
PORTVERSION=	1.1.22
CATEGORIES=	net python
MASTER_SITES=	CHEESESHOP \
		http://miketeo.net/files/Projects/${PORTNAME}/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

LICENSE=	ZLIB
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyasn1>=0:devel/py-pyasn1

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils
PORTDOCS=	*

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _modules/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} api/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
