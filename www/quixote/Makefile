# New ports collection makefile for:	quixote
# Date created:		18 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quixote
PORTVERSION=	1.2
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/files/quixote/ \
		http://bsdchat.com/dist/dryice/
DISTNAME=	Quixote-${PORTVERSION}

MAINTAINER=	dryice@liu.com.cn
COMMENT=	A framework for developing web applications in Python

USE_PYTHON=	2.0+
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 220
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/compiler/__init__.py:${PORTSDIR}/lang/py-compiler
.endif

post-install:
	@ PYTHONPATH=${PREFIX}/lib/${PYTHON_VERSION}/site-packages \
	  ${PYTHON_CMD} ${SCRIPTDIR}/compile_ptl.py \
	  ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/${PORTNAME}/demo/*.ptl
	@ ${MKDIR} ${EXAMPLESDIR}
	@ ${INSTALL_DATA} ${WRKSRC}/demo/*.cgi ${WRKSRC}/demo/*.conf \
	  ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS CHANGES LICENSE README TODO doc/*
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.post.mk>
