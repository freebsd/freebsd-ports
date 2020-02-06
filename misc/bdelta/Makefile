# Created by: Roman Bogorodskiy <novel@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bdelta
PORTVERSION=	0.3.1
DISTVERSIONPREFIX=v
CATEGORIES=	misc devel

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Advanced delta creator, patcher, and library

LICENSE=	MPL20

WRKSRC_SUBDIR=	src

USES=		gmake
USE_LDCONFIG=	yes
USE_GITHUB=	yes
GH_ACCOUNT=	jjwhitney
GH_PROJECT=	BDelta

PLIST_FILES=	bin/bdelta bin/bpatch lib/libbdelta.so
PORTDOCS=	README

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bdelta ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/bpatch ${STAGEDIR}${PREFIX}/bin
	${INSTALL_LIB} ${WRKSRC}/libbdelta.so ${STAGEDIR}${PREFIX}/lib

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/../,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
