# New ports collection makefile for:	quixote
# Date created:		18 September 2001
# Whom:	      		Johann Visagie <wjv@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	quixote
PORTVERSION=	0.4.1
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/files/quixote/
DISTNAME=	Quixote-${PORTVERSION}

MAINTAINER=	wjv@FreeBSD.org

BUILD_DEPENDS=	${PYDISTUTILS}
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/compiler/__init__.py:${PORTSDIR}/lang/py-compiler

USE_PYTHON=	yes

do-build:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py build

pre-install:
	@ ${SH} ${PKGREQ} INSTALL

do-install:
	@ cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${PYTHON_CMD} \
	  setup.py install -c -O1 --prefix=${PREFIX}

post-install:
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in ACKS CHANGES LICENSE README TODO doc/*.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
