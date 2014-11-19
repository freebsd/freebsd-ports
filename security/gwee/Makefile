# Created by: chinsan <chinsan@mail2000.com.tw>
# $FreeBSD$

PORTNAME=	gwee
PORTVERSION=	1.36
CATEGORIES=	security www
MASTER_SITES=	PACKETSTORM
MASTER_SITE_SUBDIR=	UNIX/utilities

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Tool to exploit command execution vulnerabilities in web scripts

USES=		perl5 python
USE_OPENSSL=	yes

LDFLAGS+=	-lssl -lcrypto
CFLAGS+=	-DWITH_SSL

PLIST_FILES=	bin/gwee man/man1/gwee.1.gz

do-build:
	${CC} ${CFLAGS} ${LDFLAGS} ${WRKSRC}/${PORTNAME}.c \
		-o ${WRKSRC}/${PORTNAME}

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${MANPREFIX}/man/man1

.include <bsd.port.mk>
