#define this if you want to build LaTeX too
#MAKE_LATEX=	yes

DISTFILES=	web2c.tar.gz web.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz      modes.mf 

EXTRACT_ONLY=	web2c.tar.gz web.tar.gz tex_base.tar.gz cm_tfm.tar.gz \
		mf_lib.tar.gz cm_mf.tar.gz


FTPGET=		${WRKDIR}/ftpget
TEXDIR=		${.CURDIR}


DISTNAME=	web2c-6.1

#other equivalent sites: ftp.shsu.edu dtp.dante.de
CTAN=		ftp.tex.ac.uk


.if defined (MAKE_LATEX)
DISTFILES+=	latex_mf.tar.gz latex_tfm.tar.gz latex_base.tar.gz
EXTRACT_ONLY+=	latex_base.tar.gz latex_mf.tar.gz latex_tfm.tar.gz
.endif

BASES=		mf.base cmmf.base 
FORMATS=	tex.fmt 

CFLAGS=		-O2
PREFIX=		/usr/local

pre-fetch:
	@if [ ! -d ${DISTDIR} ]; then mkdir -p ${DISTDIR}; fi
	@mkdir -p ${WRKDIR}
	@${SCRIPTDIR}/ftpget magic ${WRKDIR}

fetch: pre-fetch ${DISTFILES}

fetch-file:
	@echo ">> ${file_out} doesn't seem to exist on this system."; 
	@echo ">> Attempting to fetch it from a master site."; 
	@${FTPGET} ${CTAN} ${ftp_dir} ${file_in} ${file_out}
	@if [ ! -f ${file_out} ]; then \
		echo ">> Couldn't fetch it - please try to retreive this";\
		echo ">> port manually into ${DISTDIR} and try again."; \
		exit 1; \
	 else \
		echo ">> ${file_out} Fetched!" ; \
	 fi;
	
web2c.tar.gz: 
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
		ftp_dir=/tex-archive/systems/web2c file_in=web2c.tar.gz file_out=$@; \
	 fi;)
web.tar.gz: 
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/systems/web2c file_in=web.tar.gz file_out=$@; \
	 fi;)
cm_mf.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/fonts file_in=cm/mf.tar.gz file_out=$@; \
	 fi;)
cm_tfm.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/fonts file_in=cm/tfm.tar.gz file_out=$@; \
	 fi;)
mf_lib.tar.gz: 
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/systems/knuth file_in=lib.tar.gz file_out=$@; \
	 fi;)
modes.mf:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/systems/web2c file_in=modes.mf file_out=$@; \
	 fi;)
tex_base.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
	        ftp_dir=/tex-archive/macros file_in=plain/base.tar.gz file_out=$@; \
	 fi;)
latex_base.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
	        ftp_dir=/tex-archive/macros file_in=latex/base.tar.gz file_out=$@; \
	fi;)
latex_mf.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/fonts file_in=latex/mf.tar.gz file_out=$@; \
	 fi;)
latex_tfm.tar.gz:
	@(cd ${DISTDIR}; if [ ! -f $@ ]; then \
	  make -f ${TEXDIR}/Makefile fetch-file FTPGET=${FTPGET} \
 		ftp_dir=/tex-archive/fonts file_in=latex/tfm.tar.gz file_out=$@; \
	 fi;)


CONFIGURE_COOKIE=	${.CURDIR}/.configure_done

configure: extract ${CONFIGURE_COOKIE}

${CONFIGURE_COOKIE}:
	@echo "===>  Configuring for ${DISTNAME}"
	@if [ -f ${SCRIPTDIR}/configure ]; then \
		sh ${SCRIPTDIR}/configure ${PORTSDIR} ${.CURDIR} ${WRKSRC}; \
	fi
	@(cd ${WRKSRC}; LEX=lex; YACC=yacc; export LEX YACC; \
	  ./configure --prefix=${PREFIX})
	@(cd ${WRKDIR}; rm -rf mf; mkdir mf; cd mf; \
	  for f in `find ../cm -name \*.mf -print`; do \
	    if [ ! -f `basename $$f` ]; then \
		ln -s $$f; \
	    fi; \
	  done;\
	  for f in `find ../lib -name \*.mf -print`; do \
	    if [ ! -f `basename $$f` ]; then \
		ln -s $$f; \
	    fi; \
	  done;\
	  cp ${DISTDIR}/modes.mf .; )
.if defined (MAKE_LATEX)
	@(cd ${WRKDIR}/mf; \
	  for f in `find ../latex -name \*.mf -print`; do \
	    if [ ! -f `basename $$f` ]; then \
		ln -s $$f; \
	    fi; \
	  done;)
.endif
	@touch -f ${CONFIGURE_COOKIE}

build: configure
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/web2c; make triptrap)
	@(cd ${WRKSRC}/web2c; make run-triptrap)
	@(cd ${WRKSRC}/web2c; make clean-triptrap)
	@(cd ${WRKSRC}; make CFLAGS="${CFLAGS}" programs)
	@(cd ${WRKSRC}; MFINPUTS=${WRKDIR}/mf; export MFINPUTS;\
		make bases="${BASES}" bases)
.if defined (MAKE_LATEX)
	@(cd ${WRKDIR}/latex/base; TEXPOOL=${WRKSRC}/web2c/tex; export TEXPOOL; \
		${WRKSRC}/web2c/tex/initex unpack.ins)
	@(cd ${WRKDIR}/latex/base; TEXFONTS=${WRKSRC}/cm/tfm:${WRKSRC}/latex/tfm; \
	  export TEXFONTS; TEXINPUTS={WRKDIR}/lib:.; export TEXINPUTS; \
	  	${WRKSRC}/web2c/tex/initex latex.ltx)
.endif
	@(cd ${WRKSRC}/web2c; TEXINPUTS=${WRKDIR}/lib:${WRKSRC}; export TEXINPUTS;\
	  TEXFONTS=${WRKDIR}/cm/tfm:${WRKDIR}/latex/tfm; export TEXFONTS; \
		make fmts="${FORMATS}" fmts)

install:
	@echo "===>  Installing for ${DISTNAME}"
	@(cd ${WRKSRC}/web2c; make install-exec INSTALL_PROGRAM="/usr/bin/install -c -s")
.if defined(MAKE_LATEX)
	@(/usr/bin/install -c -m 644 ${WRKDIR}/latex/base/latex.fmt \
				${PREFIX}/lib/texmf/ini/)
.endif
	@(cd ${WRKSRC}/web2c; make install-manpages)
	@(cd ${WRKSRC}/web2c; make install-data bases="${BASES}" fmts="${FORMATS}")
	@mkdir -p ${PREFIX}/lib/texmf/fonts/tfm
	@(cd ${WRKDIR}/cm/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
.if defined(MAKE_LATEX)
	@(cd ${WRKDIR}/latex/tfm; install -c -m 644 *.tfm ${PREFIX}/lib/texmf/fonts/tfm)
.endif
	@mkdir -p ${PREFIX}/lib/texmf/mf
	@(cd ${WRKDIR}/mf; install -c -m 644 *.mf ${PREFIX}/lib/texmf/mf)
	@mkdir -p ${PREFIX}/lib/texmf/tex
	@(cd ${WRKDIR}/lib; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)
	@(cd ${WRKDIR}/plain/base; install -c -m 644 *.tex ${PREFIX}/lib/texmf/tex)
.if defined(MAKE_LATEX)
	@(cd ${WRKDIR}/latex/base; install -c -m 644 latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   *.cls *.clo *.sty *.fd *.def *.cfg ${PREFIX}/lib/texmf/tex)
	@mkdir -p ${PREFIX}/lib/texmf/MakeIndex
	@(cd ${WRKDIR}/latex/base; install -c -m 644 *.ist ${PREFIX}/lib/texmf/tex)	
.endif

.include <bsd.port.mk>
