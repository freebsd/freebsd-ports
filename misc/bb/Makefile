# Created by: Andrey Zakhvatov
# $FreeBSD$

PORTNAME=	bb
DISTVERSION=	1.3rc1
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	SF/aa-project/${PORTNAME}/${DISTVERSION}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	High quality audio-visual demonstration for text terminal

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libaa.so:graphics/aalib \
		libmikmod.so:audio/libmikmod

BROKEN_aarch64=	Fails to build: regparm is not valid on this platform

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/bb-1.3.0
PORTDOCS=	README
PLIST_FILES=	bin/bb man/man1/bb.1.gz share/bb/bb.s3m share/bb/bb2.s3m \
		share/bb/bb3.s3m

OPTIONS_DEFINE=	DOCS

pre-patch:
	@${FIND} ${WRKSRC} -type f | ${XARGS} ${REINPLACE_CMD} -E -e "s@#include +<malloc.h>@#include <stdlib.h>@g" \
		-e 's, REGISTERS \(3\),,g'

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
