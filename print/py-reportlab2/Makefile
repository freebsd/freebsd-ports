# New ports collection makefile for:	py-reportlab2
# Date created:		2006-12-31
# Whom:			Li-Wen Hsu <lwhsu@lwhsu.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab2
PORTVERSION=	2.0
CATEGORIES=	print python
MASTER_SITES=	http://www.reportlab.org/ftp/ \
		ftp://ftp.reportlab.org/ \
		http://www.cs.nctu.edu.tw/~lwhsu/ports/distfiles/:accel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ReportLab_${PORTVERSION:S/./_/}.tgz \
		rl_accel-3004.tgz:accel

MAINTAINER=	lwhsu@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

USE_PYTHON=	2.4+
USE_PYDISTUTILS=	yes

WRKSRC=		${WRKDIR}/reportlab_${PORTVERSION:S/./_/}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}
DOCS=	RML_UserGuide.pdf graphguide.pdf graphics_reference.pdf reference.pdf userguide.pdf

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py

.include <bsd.port.pre.mk>

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	${CP} ${WRKSRC}/docs/${i} ${DOCSDIR}
.endfor
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
