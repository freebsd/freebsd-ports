# $FreeBSD$

LIB = 	asm-xml
OBJS=	src/elf.So
INCS=	include/asm-xml.h

NO_PIC=
MK_PROFILE=no

LIBDIR=		${PREFIX}/lib
INCLUDEDIR=	${PREFIX}/include

src/elf.So:
	${LOCALBASE}/bin/fasm src/elf.asm src/elf.So

.include <bsd.lib.mk>
