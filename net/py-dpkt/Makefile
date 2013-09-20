# $FreeBSD$

PORTNAME=	dpkt
PORTVERSION=	1.8
CATEGORIES=	net python
MASTER_SITES=	GOOGLE_CODE
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	sbz@FreeBSD.org
COMMENT=	Python fast, simple packet creation / parsing module

USE_PYTHON=	yes
USE_PYDISTUTILS=	yes
USE_PYTHON_PREFIX=	yes

DOCSDIR=	${PREFIX}/share/doc/${PKGNAMEPREFIX:C/[0-9]+//}${PORTNAME}
EXAMPLESDIR=	${PREFIX}/share/examples/${PKGNAMEPREFIX:C/[0-9]+//}${PORTNAME}

OPTIONS_DEFINE=	DOCS

PORTDOCS=	AUTHORS CHANGES HACKING LICENSE PKG-INFO README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-install:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${DOCSDIR}
.endif
.if ${PORT_OPTIONS:MEXAMPLES}
	@${MKDIR} ${EXAMPLESDIR}
	@(cd ${WRKSRC}/examples/ && ${COPYTREE_SHARE} \* ${EXAMPLESDIR})
.endif

regression-test: extract
	@(cd ${WRKSRC} && ${PYTHON_CMD} tests/test-perf2.py)

.include <bsd.port.mk>
