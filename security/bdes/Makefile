PORTNAME=	bdes
PORTVERSION=	1993
CATEGORIES=	security
MASTER_SITES=	http://phobos69.inf.uni-konstanz.de/download/tools/ \
		LOCAL/brnrd
DISTNAME=	${PORTNAME}

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	Encrypt/decrypt using the Data Encryption Standard (DES)

LICENSE=	BSD2CLAUSE

USES=		ssl tar
WRKSRC=		${WRKDIR}/bdes.src

PLIST_FILES=	bin/bdes man/man1/bdes.1.gz

do-build:
	cd ${WRKSRC} && ${CC} ${CFLAGS} -I${OPENSSLINC} -c bdes.c
	cd ${WRKSRC} && ${CC} -o bdes bdes.o ${OPENSSLLIB}/libcrypto.so

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/bdes ${STAGEDIR}${PREFIX}/bin/bdes
	${INSTALL_MAN} ${WRKSRC}/bdes.1 ${STAGEDIR}${MANPREFIX}/man/man1/bdes.1

.include <bsd.port.mk>
