PORTNAME=	agrep
PORTVERSION=	3.41.5
CATEGORIES=	textproc

PATCH_SITES=	ftp://ftp.dinoex.org/pub/agrep/
PATCHFILES=	agrep-patch-ansi1

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Approximate grep (fast approximate pattern-matching tool)

LICENSE=	ISCL

USES=	gmake
USE_GITHUB=	yes
GH_ACCOUNT=	Wikinaut
GH_TAGNAME=	7b7f350
ALL_TARGET=	${PORTNAME}
CFLAGS+=	-Wno-pointer-sign
PORTDOCS=	CHANGES COPYRIGHT README.md

OPTIONS_DEFINE=	DOCS

post-extract:
	${RM} -v ${WRKSRC}/*.orig

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/agrep ${STAGEDIR}${PREFIX}/bin/agrep

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC}/docs && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR}/
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
