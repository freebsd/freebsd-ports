# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ttyrec
PORTVERSION=	1.0.8
PORTREVISION=	2
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tty recorder

MANPAGE=	ttyplay.1 ttyrec.1
BINS=		ttyplay ttyrec ttytime

OPTIONS_DEFINE=	OPENPTY
OPENPTY_DESC=	Use openpty instead

PLIST_FILES=	bin/ttyplay bin/ttyrec bin/ttytime \
		man/man1/ttyplay.1.gz man/man1/ttyrec.1.gz

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" \
		${WRKSRC}/Makefile

do-install:
	${INSTALL_PROGRAM} ${BINS:S,^,${WRKSRC}/,} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${MANPAGE:S,^,${WRKSRC}/,} \
		${STAGEDIR}${MANPREFIX}/man/man1

.if ${PORT_OPTIONS:MOPENPTY}
CFLAGS+=	-DHAVE_openpty -lutil
.endif

.include <bsd.port.mk>
