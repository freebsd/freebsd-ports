# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	boxes
PORTVERSION=	1.1.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://boxes.thomasjensen.com/download/ \
		http://fossies.org/unix/privat/
#		SUNSITE/utils/text
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Draws ASCII-art configurable boxes around text or code

LICENSE=	GPLv2

USES=		bison gmake
ALL_TARGET=	boxes
MAKE_ARGS=	CC="${CC}" GLOBALCONF=${GLOBALCONF} CFLAGS="${CFLAGS} -ansi -I. -Iregexp"

GLOBALCONF=	${DATADIR}/boxes-config

PLIST_FILES=	bin/${PORTNAME} \
		${DATADIR_REL}/${PORTNAME}-config \
		man/man1/${PORTNAME}.1.gz
PLIST_DIRS=	${DATADIR_REL}

PORTDOCS=	README

post-patch:
	@${RM} ${WRKSRC}/src/${PORTNAME}.h ${WRKSRC}/doc/${PORTNAME}.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTNAME}-config ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${PORTNAME}.1 \
		${STAGEDIR}${MAN1PREFIX}/man/man1/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
