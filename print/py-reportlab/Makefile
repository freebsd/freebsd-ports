# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.0
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	py-
DISTNAME=	${PORTNAME}
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org

USE_PYTHON=	yes
NO_BUILD=	yes

REPORTLABDIR=	${PYTHON_SITELIBDIR}/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

do-install:
	@${MKDIR} ${REPORTLABDIR}
.for dir in . lib pdfbase pdfgen platypus
	@${MKDIR} ${REPORTLABDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.py ${REPORTLABDIR}/${dir}
.endfor
	@${PYTHON_CMD} ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}
	@${PYTHON_CMD} -O ${PYTHON_LIBDIR}/compileall.py ${REPORTLABDIR}

	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/demos; tar cpf - * | (cd ${EXAMPLEDIR}; tar xpf -)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}
.endif

.include <bsd.port.mk>
