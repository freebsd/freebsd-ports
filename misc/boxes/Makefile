# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	boxes
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://boxes.thomasjensen.com/download/ \
		http://fossies.org/unix/privat/
#		SUNSITE/utils/text
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nemysis@FreeBSD.org
COMMENT=	Draws ASCII-art configurable boxes around text or code

LICENSE=	GPLv2

USES=		bison gmake
ALL_TARGET=	boxes
MAKE_ARGS=	CC="${CC}" GLOBALCONF=${GLOBALCONF} CFLAGS="${CFLAGS} -ansi -I. -Iregexp"

GLOBALCONF=	${DATADIR}/boxes-config

PLIST_FILES=	bin/boxes \
		${DATADIR_REL}/boxes-config \
		man/man1/boxes.1.gz
PLIST_DIRS=	${DATADIR_REL}

PORTDOCS=	README

post-patch:
	${RM} ${WRKSRC}/src/boxes.h ${WRKSRC}/doc/boxes.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boxes ${STAGEDIR}${PREFIX}/bin/
	${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/boxes-config ${STAGEDIR}${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/boxes.1 ${STAGEDIR}${MAN1PREFIX}/man/man1/

	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
