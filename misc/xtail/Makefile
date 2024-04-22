PORTNAME=	xtail
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	misc
MASTER_SITES=	http://www.unicom.com/sw/xtail/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Watches the growth of files or directories
WWW=		https://www.unicom.com/sw/xtail/

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/xtail share/man/man1/xtail.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xtail.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
