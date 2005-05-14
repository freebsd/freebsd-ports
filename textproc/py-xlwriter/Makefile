# New ports collection makefile for:	py-xlwriter
# Date created:		12 May 2005
# Whom:			Choe, Cheng-Dae
#
# $FreeBSD$
#

PORTNAME=	xlwriter
PORTVERSION=	0.4a3
CATEGORIES=	textproc python
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	pyxlwriter
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	pyXLWriter-${PORTVERSION}

MAINTAINER=	whitekid@gmail.com
COMMENT=	A python library for generating Excel-compatible spreadsheets

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_ZIP=	yes

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${FIND} ${WRKSRC}/examples -type f -exec ${INSTALL_DATA} {} ${EXAMPLESDIR} \;

.include <bsd.port.mk>
