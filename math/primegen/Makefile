PORTNAME=	primegen
PORTVERSION=	0.97
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/primegen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast library to generate prime numbers in order

USES=		groff
ALL_TARGET=	default

PLIST_FILES=	bin/primes bin/primegaps \
		include/primegen.h \
		lib/libprimegen.a \
		man/man1/primes.1.gz \
		man/man1/primegaps.1.gz \
		man/man3/primegen.3.gz

post-patch:
	@${REINPLACE_CMD} -e 's,primegen\.a,lib&,' ${WRKSRC}/Makefile \
		${WRKSRC}/TARGETS ${WRKSRC}/hier.c

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -fsigned-char -fPIC' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC}' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} '${PREFIX}' > ${WRKSRC}/conf-home

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/primes ${STAGEDIR}${PREFIX}/bin
	${INSTALL_PROGRAM} ${WRKSRC}/primegaps ${STAGEDIR}${PREFIX}/bin
	${INSTALL_DATA} ${WRKSRC}/primegen.h ${STAGEDIR}${PREFIX}/include
	${INSTALL_DATA} ${WRKSRC}/libprimegen.a ${STAGEDIR}${PREFIX}/lib
	${INSTALL_MAN} ${WRKSRC}/primes.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/primegaps.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/primegen.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
