# Created by: ijliao
# $FreeBSD$

PORTNAME=	pysmb
PORTVERSION=	1.1.16
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/files/Projects/${PORTNAME}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

OPTIONS_DEFINE=	DOCS

NO_ARCH=	yes
USES=		python
USE_PYTHON=	autoplist concurrent distutils
PORTDOCS=	*

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _modules/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} api/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
