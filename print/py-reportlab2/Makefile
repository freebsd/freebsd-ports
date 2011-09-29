# New ports collection makefile for:	py-reportlab2
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab2
PORTVERSION=	2.5
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	reportlab-${PORTVERSION}${EXTRACT_SUFX} pfbfer-${PFBFER_VERSION}.zip
EXTRACT_ONLY=	reportlab-${PORTVERSION}${EXTRACT_SUFX}

MAINTAINER=	buganini@gmail.com
COMMENT=	Library to create PDF documents using the Python language

LICENSE=	BSD

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

OPTIONS=	CJK "Adobe CMaps" on \
		FREETYPE "FreeType" on

WRKSRC=		${WRKDIR}/reportlab-${PORTVERSION}

CONFLICTS=	py2[0-9]-reportlab-[0-9]*

PFBFER_VERSION=	20070710

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	reportlab

MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCS=		reportlab-graphics-reference.pdf \
		reportlab-reference.pdf \
		reportlab-userguide.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/ports/distfiles|${DISTDIR}|g' ${WRKSRC}/setup.py
	@${REINPLACE_CMD} -e 's|pfbfer.zip|pfbfer-${PFBFER_VERSION}.zip|g' ${WRKSRC}/setup.py

.include <bsd.port.pre.mk>
.if ${ARCH} == "sparc64"
BROKEN=		Does not install on sparc64

.endif

.if !defined(WITHOUT_CJK)
RUN_DEPENDS+=	${LOCALBASE}/share/fonts/adobe-cmaps/ac15/cid2code.txt:${PORTSDIR}/print/adobe-cmaps
.endif

.if !defined(WITHOUT_FREETYPE)
LIB_DEPENDS+=	freetype.9:${PORTSDIR}/print/freetype2
.endif

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${PYTHON_CMD} genAll.py
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${CP} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
