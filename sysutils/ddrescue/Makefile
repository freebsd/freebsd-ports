# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ddrescue
PORTVERSION=	1.18.1
CATEGORIES=	sysutils
MASTER_SITES=	GNU
EXTRACT_SUFX=	.tar.lz

MAINTAINER=	jharris@widomaker.com
COMMENT=	Data recovery tool

LICENSE=	GPLv3

EXTRACT_DEPENDS=lzip:archivers/lzip

OPTIONS_DEFINE=	DOCS

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	CC="${CC}" CXX="${CXX}" CFLAGS="${CFLAGS}" \
		CXXFLAGS="${CXXFLAGS}"

INFO=		ddrescue
PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/ddrescue \
		bin/ddrescuelog \
		man/man1/ddrescue.1.gz \
		man/man1/ddrescuelog.1.gz

do-extract:
	@${MKDIR} ${WRKDIR}
	@${LOCALBASE}/bin/lzip -dc ${DISTDIR}/${DISTFILES} | \
	${TAR} -x -f - -C ${WRKDIR} --no-same-owner --no-same-permissions

do-install:
.for i in ddrescue ddrescuelog
	${INSTALL_PROGRAM} ${WRKSRC}/${i} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/doc/${i}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
.endfor
	${INSTALL_DATA} ${WRKSRC}/doc/ddrescue.info ${STAGEDIR}${PREFIX}/${INFO_PATH}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S,^,${WRKSRC}/,} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
