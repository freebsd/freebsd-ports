# New ports collection makefile for:	reportlab
# Date created:		17 August 2000
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	reportlab
PORTVERSION=	1.20
CATEGORIES=	print python
MASTER_SITES=	http://216.92.220.143/ftp/ \
		ftp://ftp.reportlab.com/ \
		http://people.freebsd.org/~perky/distfiles/:accel
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTFILES=	ReportLab_${PORTVERSION:S/./_/}.tgz \
		rl_accel-2544.tar.gz:accel

MAINTAINER=	perky@FreeBSD.org
COMMENT=	Library to create PDF documents using the Python language

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes
WRKSRC=		${WRKDIR}/reportlab_${PORTVERSION:S/./_/}/reportlab
MAKE_ENV=	PACKAGE_PATH="${REPORTLABDIR}"

REPORTLABDIR=	${PYTHONPREFIX_SITELIBDIR}/reportlab
DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX}${PORTNAME}

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local|${LOCALBASE}|g' ${WRKSRC}/rl_config.py

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
