DISTNAME=	a2ps
DISTFILES=	a2ps.V4.3.tar.gz
MASTER_SITES=	ftp://ftp.imag.fr/archive/postscript/
CATEGORIES+=	printing
NO_WRKSUBDIR=	yes
MAINTAINER=	jmz@FreeBSD.org

pre-install:
	@mkdir -p  ${PREFIX}/bin
	@mkdir -p  ${PREFIX}/man/man1
	@(cd ${WRKSRC}; make install.man)

.include <bsd.port.mk>
