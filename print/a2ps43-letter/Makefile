DISTNAME=	a2ps
DISTFILES=	a2ps.V4.3.tar.gz
MASTER_SITES=	ftp://ftp.imag.fr/archive/postscript/
NO_WRKSUBDIR=	yes

pre-install:
	@mkdir -p  ${PREFIX}/bin
	@mkdir -p  ${PREFIX}/man/man1
	@(cd ${WRKSRC}; make install.man)

.include <bsd.port.mk>
