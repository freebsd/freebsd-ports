# $FreeBSD$

PORTNAME=	sandsifter
PORTVERSION=	0.1
CATEGORIES=	security

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Processor fuzzer for x86 CPUs

BUILD_DEPENDS=	${LOCALBASE}/include/capstone/capstone.h:devel/capstone3
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>0:devel/py-capstone

USES=		gmake python localbase shebangfix

ONLY_FOR_ARCH=	amd64 i386
ONLY_FOR_ARCH_RAESON=Designed for x86

USE_GITHUB=	yes
GH_ACCOUNT=	xoreaxeaxeax
GH_TAGNAME=	dff63246fed84d90118441b8ba5b5d3bdd094427
SHEBANG_FILES=	sifter.py summarize.py

OPTIONS_DEFINE=	DOCS

PORTDOCS=	references/*

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} gui ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pyutil ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/injector ${STAGEDIR}${PREFIX}/bin
	${INSTALL_SCRIPT} ${WRKSRC}/sifter.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/summarize.py ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/sifter.py ${STAGEDIR}${PREFIX}/bin/sifter
	${RLN} ${STAGEDIR}${DATADIR}/summarize.py ${STAGEDIR}${PREFIX}/bin/summarize
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/references/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
