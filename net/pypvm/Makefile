# $FreeBSD$

PORTNAME=	pypvm
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	brooks@FreeBSD.org
COMMENT=	PVM for Python

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm

USE_PYTHON=	yes
USE_PYDISTUTILS=yes

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

NO_STAGE=	yes
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
