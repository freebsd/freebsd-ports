PKGNAME=	tex
DISTFILES=	web2c.tar.gz web.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz      modes.mf 

EXTRACT_ONLY=	web2c.tar.gz web.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz


FTPGET=		${FILESDIR}/ftpget

DISTNAME=	web2c-6.1

#other equivalent sites: ftp.shsu.edu ftp.dante.de
CTAN=		ftp.tex.ac.uk


BASES=		mf.base cmmf.base 
FORMATS=	tex.fmt 

CFLAGS=		-O2

BUILD_COOKIE=		${WRKDIR}/.build_done

web2c.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/web2c web2c.tar.gz ${DISTDIR}/$@
web.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/web2c web.tar.gz ${DISTDIR}/$@
cm_mf.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts cm/mf.tar.gz ${DISTDIR}/$@
cm_tfm.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/fonts cm/tfm.tar.gz ${DISTDIR}/$@
mf_lib.tar.gz: 
	@${FTPGET} ${CTAN} /tex-archive/systems/knuth lib.tar.gz ${DISTDIR}/$@
modes.mf:
	@${FTPGET} ${CTAN} /tex-archive/fonts/modes modes.mf ${DISTDIR}/$@
tex_base.tar.gz:
	@${FTPGET} ${CTAN} /tex-archive/macros plain/base.tar.gz ${DISTDIR}/$@

build: ${BUILD_COOKIE}

${BUILD_COOKIE}:
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/web2c; make triptrap)
	@(cd ${WRKSRC}/web2c; make run-triptrap)
	@(cd ${WRKSRC}/web2c; make clean-triptrap)

	@(cd ${WRKSRC}; make CFLAGS="${CFLAGS}" programs)
	@(cd ${WRKSRC}; MFINPUTS=${WRKDIR}/mf; export MFINPUTS;\
		make bases="${BASES}" bases)
	@(cd ${WRKSRC}/web2c; TEXINPUTS=${WRKDIR}/lib:${WRKSRC}; export TEXINPUTS;\
	  TEXFONTS=${WRKDIR}/cm/tfm:${WRKDIR}/latex/tfm; export TEXFONTS; \
		make fmts="${FORMATS}" fmts)
	@touch -f ${BUILD_COOKIE}

install:
	@echo "===>  Installing for ${DISTNAME}"
	@(cd ${WRKSRC}/web2c; make install-exec INSTALL_PROGRAM="/usr/bin/install -c -s")
	@(cd ${WRKSRC}/web2c; make install-manpages)
	@(cd ${WRKSRC}/web2c; make install-data bases="${BASES}" fmts="${FORMATS}")
	@mkdir -p ${PREFIX}/lib/texmf/fonts/tfm
	@(cd ${WRKDIR}/cm/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
	@mkdir -p ${PREFIX}/lib/texmf/mf
	@(cd ${WRKDIR}/mf; install -c -m 644 *.mf ${PREFIX}/lib/texmf/mf)
	@mkdir -p ${PREFIX}/lib/texmf/tex
	@(cd ${WRKDIR}/lib; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)
	@(cd ${WRKDIR}/plain/base; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)

.include "Makefile.inc"

.include <bsd.port.mk>
