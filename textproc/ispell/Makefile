DISTFILES=	ispell-3.1.08.tar.gz
DISTNAME=	ispell-3.1
MASTER_SITES=	ftp://ftp.cs.ucla.edu/pub/ispell-3.1/

MAKE_FLAGS=	TMPDIR=${.CURDIR} -f 

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib
	@mkdir -p ${PREFIX}/man/man1
	@mkdir -p ${PREFIX}/man/man4

.include <bsd.port.mk>
