# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	boxes
PORTVERSION=	1.3
DISTVERSIONPREFIX=	v
CATEGORIES=	misc

MAINTAINER=	olgeni@FreeBSD.org
COMMENT=	Draws ASCII-art configurable boxes around text or code

LICENSE=	GPLv2

USE_GITHUB=	yes
GH_ACCOUNT=	ascii-boxes

USES=		bison gmake
ALL_TARGET=	build
MAKE_ARGS=	CC="${CC}" GLOBALCONF=${GLOBALCONF} CFLAGS="${CFLAGS} -ansi -I. -Iregexp"

GLOBALCONF=	${DATADIR}/boxes-config

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR_REL}/${PORTNAME}-config \
		man/man1/${PORTNAME}.1.gz

PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-patch:
	@${RM} ${WRKSRC}/src/${PORTNAME}.h ${WRKSRC}/doc/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-config ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
