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

BUILD_DEPENDS=	python:${PORTSDIR}/lang/python
RUN_DEPENDS=	python:${PORTSDIR}/lang/python

NO_BUILD=	yes
PLIST_SUB=	PYVERSION=${PYVERSION}

PYVERSION=	python1.5
PYTHONSCRIPTDIR=	${PREFIX}/lib/${PYVERSION}
REPORTLABDIR=	${PYTHONSCRIPTDIR}/site-packages/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

do-install:
	@${MKDIR} ${REPORTLABDIR}
.for dir in . lib pdfbase pdfgen platypus
	@${MKDIR} ${REPORTLABDIR}/${dir}
	${INSTALL_DATA} ${WRKSRC}/${dir}/*.py ${REPORTLABDIR}/${dir}
.endfor
	${ECHO} 'reportlab' > ${PYTHONSCRIPTDIR}/reportlab.pth
	@${PREFIX}/bin/python ${PYTHONSCRIPTDIR}/compileall.py ${REPORTLABDIR}
	@${PREFIX}/bin/python -O ${PYTHONSCRIPTDIR}/compileall.py ${REPORTLABDIR}

	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/demos; tar cpf - * | (cd ${EXAMPLEDIR}; tar xpf -)

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/* ${DOCDIR}
.endif

.include <bsd.port.mk>
