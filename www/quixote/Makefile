# Created by: Johann Visagie <wjv@FreeBSD.org>
# $FreeBSD$

PORTNAME=	quixote
PORTVERSION=	2.7
CATEGORIES=	www python
MASTER_SITES=	http://quixote.ca/releases/ \
		http://dryice.name/computer/FreeBSD/distfiles/
DISTNAME=	Quixote-${PORTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A framework for developing web applications in Python

RUN_DEPENDS+=	qpcheck.py:${PORTSDIR}/www/py-qpy

USE_PYTHON=	2
USE_PYDISTUTILS=	yes
PYDISTUTILS_PKGNAME=	Quixote

NO_STAGE=	yes
.include <bsd.port.pre.mk>

post-install:
	@ PYTHONPATH=${PREFIX}/lib/${PYTHON_VERSION}/site-packages \
	  ${PYTHON_CMD} ${SCRIPTDIR}/compile_ptl.py \
	  ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/${PORTNAME}/demo/*.ptl

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS.txt CHANGES.txt LICENSE.txt README.txt TODO doc/*
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
