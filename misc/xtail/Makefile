# Created by: gmarco@giovannelli.it
# $FreeBSD$

PORTNAME=	xtail
PORTVERSION=	2.1
CATEGORIES=	misc
MASTER_SITES=	http://www.unicom.com/sw/xtail/ \
		http://utenti.gufi.org/~gmarco/files/distfiles/

MAINTAINER=	gmarco@giovannelli.it
COMMENT=	Watches the growth of files or directories

HAS_CONFIGURE=	yes

PLIST_FILES=	bin/xtail man/man1/xtail.1.gz

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/xtail ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/xtail.1 ${STAGEDIR}${PREFIX}/man/man1

.include <bsd.port.mk>
