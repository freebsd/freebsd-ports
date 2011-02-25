# New ports collection makefile for:	py-qp
# Date created:		14 Nov 2006
# Whom:	      		Dryice Liu <dryice@dryice.name>
#
# $FreeBSD$
#

PORTNAME=	qp
PORTVERSION=	2.0
PORTREVISION=	1
CATEGORIES=	www python
MASTER_SITES=	http://www.mems-exchange.org/software/qp/ \
		${MASTER_SITE_LOCAL} \
		http://dryice.name/computer/FreeBSD/distfiles/
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A python web framework to use qpy and durus together

BUILD_DEPENDS+=	qpcheck.py:${PORTSDIR}/www/py-qpy
BUILD_DEPENDS+=	durus:${PORTSDIR}/devel/py-durus
BUILD_DEPENDS+=	pythoni:${PORTSDIR}/devel/py-repl
RUN_DEPENDS+=	${BUILD_DEPENDS}

USE_PYTHON=	2.5+
USE_PYDISTUTILS=	yes
SUB_FILES+=	pkg-message
SUB_LIST+=	PYTHON_VERSION=${PYTHON_VERSION}

.include <bsd.port.pre.mk>

post-install:
	@ PYTHONPATH=${PREFIX}/lib/${PYTHON_VERSION}/site-packages \
	  ${PYTHON_CMD} -c "import qp.fill"; \
     	  cd ${WRKSRC}; \
	  ${PYTHON_CMD} setup.py install_demo_sites ${EXAMPLESDIR}

.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
.for docfile in CHANGES.txt LICENSE.txt README.txt
	@ ${INSTALL_DATA} ${WRKSRC}/${docfile} ${DOCSDIR}
.endfor
.endif

	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
