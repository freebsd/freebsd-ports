# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	3.0
CATEGORIES=	print python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	python@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

USE_GITHUB=	yes
GH_ACCOUNT=	behdad

USES=		python
USE_PYTHON=	autoplist distutils
NO_ARCH=	yes

DOCSDIR=	${PREFIX}/share/doc/${PYTHON_PKGNAMEPREFIX}-fonttools
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' ${WRKSRC}/setup.py

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
