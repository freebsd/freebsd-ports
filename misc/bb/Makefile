# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	bb
PORTVERSION=	1.3.r1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/aa-project/${PORTNAME}/1.3rc1
DISTNAME=	${PORTNAME}-${PORTVERSION:S/.r/rc/}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality audio-visual demonstration for text terminal

LIB_DEPENDS=	libaa.so:${PORTSDIR}/graphics/aalib \
		libmikmod.so:${PORTSDIR}/audio/libmikmod

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/bb-1.3.0
PORTDOCS=	README
PLIST_FILES=	bin/bb man/man1/bb.1.gz share/bb/bb.s3m share/bb/bb2.s3m \
		share/bb/bb3.s3m
PLIST_DIRS=	share/bb

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -E -e "s@#include +<malloc.h>@#include <stdlib.h>@g" \
		-e 's, REGISTERS \(3\),,g'

post-install:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
