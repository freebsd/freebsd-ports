DISTNAME=	Fudgit_2.41
DISTFILES=	fudgit_2.41.tar.gz
MASTER_SITES=	ftp://ftp.physics.mcgill.ca/pub/Fudgit/
USE_GMAKE=	yes

pre-install:
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/lib/fudgit
	@mkdir -p ${PREFIX}/man/man1
	@(cd ${WRKSRC}/examples; cp * ${PREFIX}/lib/fudgit)
	
.include <bsd.port.mk>
