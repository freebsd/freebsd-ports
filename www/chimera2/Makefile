DISTNAME=	chimera-1.61
USE_IMAKE=	yes
MASTER_SITES=	ftp://ftp.cs.unlv.edu/pub/chimera/

pre-install:
	@mkdir -p ${PREFIX}/man/man1
	@install -c -m 644 ${WRKSRC}/src/chimera.man ${PREFIX}/man/man1/chimera.1

.include <bsd.port.mk>
