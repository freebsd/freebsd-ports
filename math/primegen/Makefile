# New ports collection makefile for:	primegen
# Date created:				Fri Mar 27 2009 12:04:22 UTC
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	primegen
PORTVERSION=	0.97
CATEGORIES=	math
MASTER_SITES=	http://cr.yp.to/primegen/

MAINTAINER=	lioux@FreeBSD.org
COMMENT=	A small, fast library to generate prime numbers in order

ALL_TARGET=
MAKE_JOBS_SAFE=	yes

MAN1=	primes.1 primegaps.1
MAN3=	primegen.3

PROGRAM_FILES=	primes primegaps
HEADER_FILES=	primegen.h
LIB_FILES=	libprimegen.a

# programs
PLIST_FILES+=	${PROGRAM_FILES:S,^,bin/,}

# header files
PLIST_FILES+=	${HEADER_FILES:S,^,include/,}

# libraries
PLIST_FILES+=	${LIB_FILES:S,^,lib/,}

post-patch:
	@${FIND} ${WRKSRC} -type f -exec \
		${REINPLACE_CMD} -E -e 's!(primegen.a)!lib\1!' {} \;

do-configure:
	@${ECHO_CMD} '${CC} ${CFLAGS} -fsigned-char -fPIC' > ${WRKSRC}/conf-cc
	@${ECHO_CMD} '${CC}' > ${WRKSRC}/conf-ld
	@${ECHO_CMD} '${PREFIX}' > ${WRKSRC}/conf-home

do-install:
.for file in ${PROGRAM_FILES}
	@${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.for file in ${HEADER_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/include
.endfor
.for file in ${LIB_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${file} ${PREFIX}/lib
.endfor
.for file in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${MAN1PREFIX}/man/man1
.endfor
.for file in ${MAN3}
	@${INSTALL_MAN} ${WRKSRC}/${file} ${MAN3PREFIX}/man/man3
.endfor

.include <bsd.port.mk>
