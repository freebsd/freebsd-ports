PORTNAME=	samefile
PORTVERSION=	2.15
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	http://www.schweikhardt.net/

MAINTAINER=	schweikh@FreeBSD.org
COMMENT=	Find files with identical contents

CONFLICTS=	samesame

GNU_CONFIGURE=	yes

CFLAGS+=	-ansi -pedantic -Wall -Wshadow -Wpointer-arith -Wbad-function-cast -Wcast-qual -Wcast-align -Wstrict-prototypes -Wmissing-prototypes -Wmissing-declarations -Wredundant-decls -Wnested-externs -Winline -Wno-long-long

PLIST_FILES=	bin/samefile man/man1/samefile.1.gz

post-build:
	@${ECHO_MSG} "   >>>>                        <<<<"
	@${ECHO_MSG} "   >>>> Running the test suite <<<<"
	@${ECHO_MSG} "   >>>>                        <<<<"
	cd ${WRKSRC}; ${MAKE} test

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/samefile

.include <bsd.port.mk>
