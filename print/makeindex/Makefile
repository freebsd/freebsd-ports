DISTFILES=	makeindex-3.0.8.tar.Z
DISTNAME=	makeindex

MASTER_SITES=	ftp://achilles.doc.ic.ac.uk/tex/contrib/Schrod/
CATEGORIES+=	printing
MAINTAINER=	jmz@FreeBSD.org

build: configure pre-build
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make)

install:
	@echo "===>  Installing for ${DISTNAME}"
	@mkdir -p ${PREFIX}/lib/texmf/makeindx
	@mkdir -p ${PREFIX}/bin
	@mkdir -p ${PREFIX}/man/man1
	@(cd ${WRKSRC}/src-3.0/regexp; make)
	@(cd ${WRKSRC}/src-3.0; make install)
	@(cd ${WRKSRC}/doc; \
	  sed -e s:/usr/local/lib/tex/macros/:${PREFIX}/lib/texmf/makeindx/: \
	      <makeindex.l >makeindex.1; \
	  install -c -m 644 makeindex.1 ${PREFIX}/man/man1/)

.include <bsd.port.mk>
