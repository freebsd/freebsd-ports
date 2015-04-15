# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	2.4
PORTREVISION=	4
CATEGORIES=	print python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

BUILD_DEPENDS=	${PYNUMPY} ${PYXML}
RUN_DEPENDS=	${PYNUMPY} ${PYXML}

OPTIONS_DEFINE=	DOCS

USES=		python
USE_PYTHON=	distutils autoplist

DOCSDIR=	${PREFIX}/share/doc/py-fonttools
PORTDOCS=	*

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' ${WRKSRC}/setup.py

post-install:
	${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/FontTools/fontTools/misc/eexecOp.so
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/ChangeLog ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
