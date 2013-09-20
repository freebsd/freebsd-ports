# Created by: Wen Heping <wenheping@gmail.com>
# $FreeBSD$

PORTNAME=	nzmath
PORTVERSION=	1.2.0
CATEGORIES=	math python
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}/NZMATH-${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}
DISTNAME=	NZMATH-${PORTVERSION}

MAINTAINER=	wen@FreeBSD.org
COMMENT=	Number theory oriented calculation system

USE_PYTHON=		yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	NZMATH

NO_STAGE=	yes
post-install:
.if !defined(NOPORTDATA)
	${MKDIR} ${DATADIR}
	${CP} ${WRKSRC}/data/discriminant.csv ${DATADIR}
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKSRC}/manual/*.pdf ${DOCSDIR}
.endif

.include <bsd.port.mk>
