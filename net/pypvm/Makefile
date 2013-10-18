# $FreeBSD$

PORTNAME=	pypvm
PORTVERSION=	0.94
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	PVM for Python

BUILD_DEPENDS=	pvm:${PORTSDIR}/net/pvm

DEPRECATED=	Dead upstream and suspected that there are no users of port
EXPIRATION_DATE=	2014-01-01

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
PORTDOCS=	ChangeLog \
		README

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_SCRIPT} ${EXAMPLEFILES:S|^|${WRKSRC}/|} \
	     ${STAGEDIR}${EXAMPLESDIR}
.if !defined(NOPORTDOCS)
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}
.endif

.include <bsd.port.mk>
