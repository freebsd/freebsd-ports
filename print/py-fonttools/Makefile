# Created by: Joseph Koshy <jkoshy@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fonttools
PORTVERSION=	2.4
PORTREVISION=	1
CATEGORIES=	print python
MASTER_SITES=	SF/${PORTNAME}/${PORTVERSION}
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Open source library for manipulating fonts, written in Python

BUILD_DEPENDS=	${PYNUMPY} ${PYXML}
RUN_DEPENDS=	${PYNUMPY} ${PYXML}

OPTIONS_DEFINE=	DOCS

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
PYDISTUTILS_EGGINFODIR=	${PYTHON_SITELIBDIR}/FontTools

MAN1=		ttx.1

DOCSDIR=	${PREFIX}/share/doc/py-fonttools

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|share/man/man1|man/man1|g' ${WRKSRC}/setup.py

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.html ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/Doc/*.txt ${DOCSDIR}
.endif

.include <bsd.port.mk>
