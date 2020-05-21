# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddrescue
PORTVERSION=	1.25
CATEGORIES=	sysutils
MASTER_SITES=	GNU

MAINTAINER=	jharris@widomaker.com
COMMENT=	Data recovery tool

LICENSE=	GPLv2

USES=		tar:lz
HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

INFO=		ddrescue
PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/ddrescue \
		bin/ddrescuelog \
		man/man1/ddrescue.1.gz \
		man/man1/ddrescuelog.1.gz

OPTIONS_DEFINE=	DOCS

do-install:
.for i in ddrescue ddrescuelog
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/ddrescue.info ${STAGEDIR}${PREFIX}/${INFO_PATH}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
