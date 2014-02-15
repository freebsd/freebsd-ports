# Created by: Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
# $FreeBSD$

PORTNAME=	primegen
PORTVERSION=	0.97
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/primegen/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small, fast library to generate prime numbers in order

ALL_TARGET=

PROGRAM_FILES=	primes primegaps
HEADER_FILES=	primegen.h
LIB_FILES=	libprimegen.a

# programs
PLIST_FILES+=	${PROGRAM_FILES:S,^,bin/,}

# header files
PLIST_FILES+=	${HEADER_FILES:S,^,include/,}

# libraries
PLIST_FILES+=	${LIB_FILES:S,^,lib/,}

# man pages
PLIST_FILES+=	man/man1/primes.1.gz man/man1/primegaps.1.gz \
		man/man3/primegen.3.gz

post-patch:
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E -e 's!(primegen.a)!lib\1!' {} \;

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -fsigned-char -fPIC' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC}' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} '${PREFIX}' > ${WRKSRC}/conf-home

do-install:
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/include
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/lib
.endfor
	@${INSTALL_MAN} ${WRKSRC}/primes.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/primegaps.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/primegen.3 ${STAGEDIR}${MAN3PREFIX}/man/man3

.include <bsd.port.mk>
