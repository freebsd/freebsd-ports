# New ports collection makefile for:	PyRTF
# Date created:		09 May 2005
# Whom:			Thomas Gellekum <tg@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rtf
PORTVERSION=	0.45
CATEGORIES=	print python
MASTER_SITES=	SF/py${PORTNAME}/py${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	PyRTF-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library to create RTF documents using the Python language

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	PyRTF

EXAMPLESDIR=	${PREFIX}/share/examples/py-rtf

post-install:
	@${MKDIR} ${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/examples/* ${EXAMPLESDIR}

.include <bsd.port.mk>
