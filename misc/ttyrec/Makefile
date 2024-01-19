PORTNAME=	ttyrec
PORTVERSION=	1.0.8
PORTREVISION=	4
CATEGORIES=	misc
MASTER_SITES=	http://0xcc.net/ttyrec/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tty recorder
WWW=		http://0xcc.net/ttyrec/index.html

LICENSE=	BSD4CLAUSE

OPTIONS_DEFINE=	OPENPTY
OPENPTY_DESC=	Use openpty instead
OPTIONS_DEFAULT=	OPENPTY

PLIST_FILES=	bin/ttyplay bin/ttyrec bin/ttytime \
		share/man/man1/ttyplay.1.gz share/man/man1/ttyrec.1.gz

OPENPTY_CFLAGS=	-DHAVE_openpty -lutil

post-patch:
	@${REINPLACE_CMD} -e "s|^CC|#CC|g" -e "s|^CFLAGS|#CFLAGS|g" ${WRKSRC}/Makefile

do-install:
	cd ${WRKSRC}/ && ${INSTALL_PROGRAM} ttyplay ttyrec ttytime ${STAGEDIR}${PREFIX}/bin/
	cd ${WRKSRC}/ && ${INSTALL_MAN} ttyplay.1 ttyrec.1 ${STAGEDIR}${PREFIX}/share/man/man1/

.include <bsd.port.mk>
