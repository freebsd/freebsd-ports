# New ports collection makefile for:	quixote
# Date created:		18 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quixote
PORTVERSION=	0.5.1
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/files/quixote/
DISTNAME=	Quixote-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes

.include <bsd.port.pre.mk>

.if ${PYTHON_REL} < 220
RUN_DEPENDS+=	${PYTHON_SITELIBDIR}/compiler/__init__.py:${PORTSDIR}/lang/py-compiler
.endif

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

post-install:
	@ PYTHONPATH=${PREFIX}/lib/${PYTHON_VERSION}/site-packages \
	  ${PYTHON_CMD} ${SCRIPTDIR}/compile_ptl.py \
	  ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/${PORTNAME}/demo/*.ptl \
	  ${PREFIX}/lib/${PYTHON_VERSION}/site-packages/${PORTNAME}/form/*.ptl
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
