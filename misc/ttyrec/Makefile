# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttyrec
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tty recorder

LICENSE=	BSD4CLAUSE

OPTIONS_DEFINE=	OPENPTY
OPENPTY_DESC=	Use openpty instead

PLIST_FILES=	bin/ttyplay bin/ttyrec bin/ttytime \
		man/man1/ttyplay.1.gz man/man1/ttyrec.1.gz

OPENPTY_CFLAGS=	-DHAVE_openpty -lutil

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ttyplay ttyrec ttytime ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_MAN} ttyplay.1 ttyrec.1 ${STAGEDIR}${MANPREFIX}/man/man1/

.include <bsd.port.mk>
