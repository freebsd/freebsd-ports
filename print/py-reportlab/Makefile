# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.19
CATEGORIES=	print python
MASTER_SITES=	http://216.92.220.143/ftp/ \
		ftp://ftp.reportlab.com/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	ReportLab_${PORTVERSION:S/./_/}
EXTRACT_SUFX=	.tgz

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
USE_REINPLACE=	yes
WRKSRC=		${WRKDIR}/reportlab-${PORTVERSION:S/./_/}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
