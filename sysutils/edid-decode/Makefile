# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	edid-decode
PORTVERSION=	0.1.20161109
CATEGORIES=	sysutils
MASTER_SITES=	LOCAL/ehaupt

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Decodes binary EDID information from monitors

LICENSE=	MIT

USES=		tar:xz

PLIST_FILES=	bin/edid-decode man/man1/edid-decode.1.gz

do-build:
	${CC} ${CFLAGS} ${WRKSRC}/${PORTNAME}.c -o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
