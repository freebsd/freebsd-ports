# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.14
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org

RUN_DEPENDS=	${PYTHON_SITELIBDIR}/_imaging.so:${PORTSDIR}/graphics/py-imaging

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
NO_WRKSUBDIR=	yes

REPORTLABDIR=	${PREFIX}/lib/${PYTHON_VERSION}/site-packages/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

post-patch:
	${MV} ${WRKSRC}/reportlab/lib/setup.py ${WRKDIR}

post-install:
	${MKDIR} ${REPORTLABDIR}/fonts
.for fontfile in LeERC___.AFM LeERC___.PFB
	(cd ${WRKDIR}/reportlab/fonts; \
		${INSTALL_DATA} ${fontfile} ${REPORTLABDIR}/fonts)
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/reportlab/demos; tar cpf - * | (cd ${EXAMPLEDIR}; tar xpf -)

	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/reportlab/docs/*.pdf ${DOCDIR}
.endif

.include <bsd.port.mk>
