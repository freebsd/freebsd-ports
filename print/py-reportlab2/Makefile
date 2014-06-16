# Created by: Li-Wen Hsu <lwhsu@lwhsu.org>
# $FreeBSD$

PORTNAME=	reportlab
PORTVERSION=	2.7
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

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

OPTIONS_DEFINE=	DOCS

CONFLICTS=	py*-reportlab[^2]-[^2].* \
		py*-reportlab-[^2].*

PORTSCOUT=	limit:^2\.

PFBFER_VERSION=	20070710

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_AUTOPLIST=	yes

DOCS=		reportlab-graphics-reference.pdf \
		reportlab-reference.pdf \
		reportlab-userguide.pdf

DOCS_PLIST_FILES=	${DOCSDIR}/reportlab-graphics-reference.pdf \
			${DOCSDIR}/reportlab-reference.pdf \
			${DOCSDIR}/reportlab-userguide.pdf
DOCS_PLIST_DIRS=	${DOCSDIR}

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
.for i in ${DOCS}
	${CP} ${WRKSRC}/docs/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
