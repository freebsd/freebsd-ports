# Created by: ijliao
# $FreeBSD$

PORTNAME=	smb
PORTVERSION=	1.1.8
CATEGORIES=	net python
MASTER_SITES=	http://miketeo.net/files/Projects/py${PORTNAME}/ \
		CHEESESHOP
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pysmb-${PORTVERSION}

MAINTAINER=	rm@FreeBSD.org
COMMENT=	SMB/CIFS library written in Python

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}asn1>=0:${PORTSDIR}/devel/py-asn1

OPTIONS_DEFINE=	DOCS

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}smb
PORTDOCS=	*

.include <bsd.port.options.mk>

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _modules/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} _static/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${COPYTREE_SHARE} api/ ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.html ${STAGEDIR}${DOCSDIR}/)
	(cd ${WRKSRC}/docs/html/ && ${CP} *.js ${STAGEDIR}${DOCSDIR}/)

.include <bsd.port.mk>
