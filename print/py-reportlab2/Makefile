# New ports collection makefile for:	py-reportlab2
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab2
PORTVERSION=	2.4
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.com/ftp/ \
		ftp://ftp.reportlab.org/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

BUILD_DEPENDS=	${PYTHON_PKGNAMEPREFIX}imaging>0:${PORTSDIR}/graphics/py-imaging

CONFLICTS=	py2[0-9]-reportlab-[0-9]*

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	reportlab

MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCS=		reportlab-graphics-reference.pdf \
		reportlab-reference.pdf \
		reportlab-userguide.pdf

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	@cd ${WRKSRC}/docs && ${PYTHON_CMD} genAll.py
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${CP} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
