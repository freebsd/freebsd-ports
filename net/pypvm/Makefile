# Ports collection makefile for:	pypvm
# Date created:				Wed, Jan 19 2005
# Whom:					Brooks Davis <brooks@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	pypvm
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	PVM for Python

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm

USE_PYTHON=	YES
USE_PYDISTUTILS=YES

PLIST_FILES=	%%PYTHON_SITELIBDIR%%/pypvm.py \
		%%PYTHON_SITELIBDIR%%/pypvm_core.so \
		%%PYTHON_SITELIBDIR%%/pypvm.pyc \
		%%PYTHON_SITELIBDIR%%/pypvm.pyo
EXAMPLEFILES=	master_test.py \
		slave_test.py
PLIST_FILES+=	${EXAMPLEFILES:S|^|%%EXAMPLESDIR%%/|}
PLIST_DIRS+=	%%EXAMPLESDIR%%
.if !defined(NOPORTDOCS)
PORTDOCS=	ChangeLog \
		README
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64" || ${ARCH} == "amd64"
BROKEN=		pvm port needs to provide shared libraries
.endif

post-install:
	${MKDIR} ${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLEFILES:S|^|${WRKSRC}/|} ${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.post.mk>
