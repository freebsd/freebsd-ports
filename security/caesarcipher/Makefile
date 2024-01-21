PORTNAME=	caesarcipher
PORTVERSION=	1.1
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	http://www.olivermahmoudi.com/files/

MAINTAINER=	fbsd@olivermahmoudi.com
COMMENT=	Caesar cipher cryptography tool
WWW=		https://www.olivermahmoudi.com/programming/caesar-cipher/

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

PLIST_FILES=	bin/caesarcipher \
		share/man/man1/caesarcipher.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} ${LDFLAGS} -o ${PORTNAME} ${PORTNAME}.c

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/${PORTNAME}.1 ${STAGEDIR}${PREFIX}/share/man/man1

.include <bsd.port.mk>
