DISTFILES=	xdvi.tar.Z
DISTNAME=	xdvi
MASTER_SITES=	ftp://ftp.x.org/contrib/applications/
USE_IMAKE=	yes
USE_GMAKE=	yes
IS_INTERACTIVE=	yes

install:
	@echo "===>  Installing for ${DISTNAME}"
	@mkdir -p /usr/local/man/man1
	@mkdir -p /usr/local/bin
	@(cd ${WRKSRC}; ${GMAKE} install.man \
		MANDIR=${PREFIX}/man/man1 MANSUFFIX=1)
	@(cd ${WRKSRC}; ${GMAKE} ${MAKE_FLAGS} ${MAKEFILE} xdvi.man)
	@(cd ${WRKSRC}; ${GMAKE} -f Makefile install BINDIR=${PREFIX}/bin)
	@(cd ${WRKSRC}; install -c -m 755 -o bin MakeTeXPK ${PREFIX}/bin)

.include <bsd.port.mk>
