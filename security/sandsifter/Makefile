# $FreeBSD$

PORTNAME=	sandsifter
PORTVERSION=	1.04
DISTVERSIONPREFIX=v
PORTREVISION=	1
CATEGORIES=	security

MAINTAINER=	rene@FreeBSD.org
COMMENT=	Processor fuzzer for x86 CPUs

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

ONLY_FOR_ARCHS=	amd64 i386
ONLY_FOR_ARCHS_REASON=Designed for x86

BUILD_DEPENDS=	${LOCALBASE}/include/capstone/capstone.h:devel/capstone4
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}capstone>0:devel/py-capstone@${PY_FLAVOR}

USES=		gmake python:2.7 localbase shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	rigred

SHEBANG_FILES=	sifter.py sifter-summarize.py

OPTIONS_DEFINE=	DOCS

PORTDOCS=	references/*

post-patch:
	${REINPLACE_CMD} -e 's,/usr/sbin,${PREFIX}/sbin,' ${WRKSRC}/sifter.py

do-install:
	(cd ${WRKSRC} && ${COPYTREE_SHARE} gui ${STAGEDIR}${DATADIR})
	(cd ${WRKSRC} && ${COPYTREE_SHARE} pyutil ${STAGEDIR}${DATADIR})
	${INSTALL_PROGRAM} ${WRKSRC}/sifter-injector ${STAGEDIR}${PREFIX}/sbin
	${INSTALL_SCRIPT} ${WRKSRC}/sifter.py ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/sifter-summarize.py ${STAGEDIR}${DATADIR}
	${RLN} ${STAGEDIR}${DATADIR}/sifter.py ${STAGEDIR}${PREFIX}/bin/sifter
	${RLN} ${STAGEDIR}${DATADIR}/sifter-summarize.py ${STAGEDIR}${PREFIX}/bin/sifter-summarize
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}

post-install-DOCS-on:
	${INSTALL_DATA} ${WRKSRC}/references/* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
