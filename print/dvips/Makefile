DISTFILES=	dvips558.tar.gz
DISTNAME=	dvips
MASTER_SITES=	ftp://ftp.tex.ac.uk/tex-archive/dviware/dvips/
CATEGORIES+=	printing
IS_INTERACTIVE=	yes

pre-install:
	@mkdir -p ${PREFIX}/lib/texmf
	@mkdir -p ${PREFIX}/man/man1

.include <bsd.port.mk>
