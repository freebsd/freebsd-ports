# $FreeBSD$

LIB = 	asm-xml
OBJS=	src/elf.So
INCS=	include/asm-xml.h

NO_PIC=
NO_PROFILE=

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include

src/elf.So:
	${LOCALBASE}/bin/fasm src/elf.asm src/elf.So

.include <bsd.lib.mk>
