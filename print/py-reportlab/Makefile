# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.17
CATEGORIES=	print python
MASTER_SITES=	ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCDIR=		${PREFIX}/share/doc/reportlab

post-patch:
	${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py

post-install:
#	${MKDIR} ${REPORTLABDIR}/fonts
#.for fontfile in LeERC___.AFM LeERC___.PFB
#	(cd ${WRKSRC}/fonts; \
#		${INSTALL_DATA} ${fontfile} ${REPORTLABDIR}/fonts)
#.endfor

.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCDIR}
	${INSTALL_DATA} ${WRKSRC}/docs/*.pdf ${DOCDIR}
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
