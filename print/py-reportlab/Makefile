# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.16
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
USE_REINPLACE=	yes
NO_WRKSUBDIR=	yes

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab
EXAMPLEDIR=	${PREFIX}/share/examples/reportlab

post-patch:
	${MV} ${WRKSRC}/reportlab/lib/setup.py ${WRKDIR}
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/reportlab/rl_config.py

post-install:
	${MKDIR} ${REPORTLABDIR}/fonts
.for fontfile in LeERC___.AFM LeERC___.PFB
	(cd ${WRKDIR}/reportlab/fonts; \
		${INSTALL_DATA} ${fontfile} ${REPORTLABDIR}/fonts)
.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${EXAMPLEDIR}
	cd ${WRKSRC}/reportlab/demos; ${TAR} cpf - * | (cd ${EXAMPLEDIR}; ${TAR} xpf -)

	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/reportlab/docs/*.pdf ${DOCDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
