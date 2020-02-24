# Created by: Kevin Golding <ports@caomhin.org>
# $FreeBSD$

PORTNAME=	trml2pdf
PORTVERSION=	1.2
PORTREVISION=	6
CATEGORIES=	print python
MASTER_SITES=	SF/kraft/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@caomhin.org
COMMENT=	Tiny RML2PDF easily creates PDF documents

LICENSE=	LGPL21

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-08-15

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow6>0:graphics/py-pillow6@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}reportlab>=0:print/py-reportlab@${PY_FLAVOR}

USES=		python:2.7 shebangfix tar:bzip2
USE_PYTHON=	flavors

NO_BUILD=	yes
NO_ARCH=	yes

SHEBANG_FILES=	trml2pdf/trml2pdf.py

DOCSDIR=	${PREFIX}/share/doc/py-${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/py-${PORTNAME}

OPTIONS_DEFINE=	DOCS EXAMPLES

do-install:
	@${MKDIR} ${STAGEDIR}${PYTHON_SITELIBDIR}/trml2pdf
	${INSTALL_SCRIPT} ${WRKSRC}/trml2pdf/* \
		${STAGEDIR}${PYTHON_SITELIBDIR}/trml2pdf

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.txt ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${CP} -R ${WRKSRC}/rmls/ ${STAGEDIR}${EXAMPLESDIR}/rmls

.include <bsd.port.mk>
