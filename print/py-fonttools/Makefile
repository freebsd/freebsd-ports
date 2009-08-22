# New ports collection makefile for:	py-fonttools
# Date created:				2 January 2001
# Whom:                 		Joseph Koshy <jkoshy@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	fonttools
PORTVERSION=	2.2
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	SF/${PORTNAME}/Source%20code/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An open source library for manipulating fonts, written in Python

BUILD_DEPENDS=	${PYNUMPY} ${PYXML}
RUN_DEPENDS=	${PYNUMPY} ${PYXML}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}/FontTools

MAN1=		ttx.1

DOCSDIR=	${PREFIX}/share/doc/py-fonttools

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
