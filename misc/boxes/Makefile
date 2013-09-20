# Created by: Patrick Seal <patseal@hyperhost.net>
# $FreeBSD$

PORTNAME=	boxes
PORTVERSION=	1.1.1
CATEGORIES=	misc
MASTER_SITES=	http://boxes.thomasjensen.com/download/ \
		http://fossies.org/unix/privat/
#		SUNSITE/utils/text
EXTRACT_SUFX=	.src.tar.gz

MAINTAINER=	nemysis@gmx.ch
COMMENT=	Draws ASCII-art configurable boxes around text or code

LICENSE=	GPLv2

USE_GMAKE=	yes
USES=		bison
ALL_TARGET=	boxes
MAKE_ARGS=	CC="${CC}" GLOBALCONF=${GLOBALCONF} CFLAGS="${CFLAGS} -ansi -I. -Iregexp"

GLOBALCONF=	${DATADIR}/boxes-config

PLIST_FILES=	bin/boxes \
		${DATADIR_REL}/boxes-config
PLIST_DIRS=	${DATADIR_REL}

MAN1=		boxes.1

PORTDOCS=	README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
	${RM} ${WRKSRC}/src/boxes.h ${WRKSRC}/doc/boxes.1

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/src/boxes ${PREFIX}/bin
	${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/boxes-config ${DATADIR}
	${INSTALL_MAN} ${WRKSRC}/doc/${MAN1} ${MAN1PREFIX}/man/man1

.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif

.include <bsd.port.mk>
