# $FreeBSD$

MANDIR	=	${PREFIX}/man/man

MAN1	=	hdf.1 hdfunpac.1
MAN3	=	gr_chunk.3

.include <bsd.man.mk>

install: all-man maninstall

clean:
	-rm -f *.gz

all: all-man

depend:
