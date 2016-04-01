# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	reportlab
PORTVERSION=	2.7
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
PKGNAMESUFFIX=	2
DISTFILES=	${DISTNAME}${EXTRACT_SUFX} \
		pfbfer-${PFBFER_VERSION}.zip
EXTRACT_ONLY=	${DISTNAME}${EXTRACT_SUFX}

MAINTAINER=	kozlov.sergey.404@gmail.com
COMMENT=	Library to create PDF documents using the Python language

LICENSE=	BSD3CLAUSE

BROKEN=		is not compatible with the current version of pillow
DEPRECATED=	no longer supported - use reportlab 3.x (py-reportlab) instead
EXPIRATION_DATE=2016-05-02

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pillow>0:graphics/py-pillow

OPTIONS_DEFINE=	DOCS

CONFLICTS=	py*-reportlab[^2]-[^2].* \
		py*-reportlab-[^2].*

PORTSCOUT=	limit:^2\.

PFBFER_VERSION=	20070710

USES=		python:2
USE_PYTHON=	autoplist distutils

PORTDOCS=	reportlab-graphics-reference.pdf \
		reportlab-reference.pdf \
		reportlab-userguide.pdf

.include <bsd.port.options.mk>

.if ${ARCH} == "sparc64"
BROKEN=	Does not install on sparc64
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|http://www.reportlab.com/ftp|file://${DISTDIR}|g' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@cd ${WRKSRC}/docs && \
	PYTHONPATH=${STAGEDIR}${PYTHON_SITELIBDIR} ${PYTHON_CMD} genAll.py
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${CP} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
