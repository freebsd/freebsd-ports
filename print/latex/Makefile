DISTFILES=	latex_mf.tar.gz latex_tfm.tar.gz latex_base.tar.gz
DISTNAME=	latex

FTPGET=		${WRKDIR}/ftpget
TEXDIR=		${.CURDIR}

#other equivalent sites: ftp.shsu.edu dtp.dante.de
CTAN=		ftp.tex.ac.uk


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

build: configure
	@echo "===>  Building for ${DISTNAME}"
	@(cd ${WRKSRC}/base; initex unpack.ins)
	@(cd ${WRKSRC}/base; TEXFONTS=${WRKSRC}/tfm:; export TEXFONTS; \
		initex latex.ltx)

install:
	@echo "===>  Installing for ${DISTNAME}"
	@(/usr/bin/install -c -m 644 ${WRKSRC}/base/latex.fmt \
				/usr/local/lib/texmf/ini/)
	@(cd ${WRKSRC}/tfm; install -c -m 644 *.tfm /usr/local/lib/texmf/fonts/tfm)
	@(cd ${WRKSRC}/mf; install -c -m 644 *.mf /usr/local/lib/texmf/mf)
	@(cd ${WRKSRC}/base; install -c -m 644 latexbug.tex testpage.tex \
	   lablst.tex idx.tex nfssfont.tex small2e.tex sample2e.tex docstrip.tex \
	   *.cls *.clo *.sty *.fd *.def *.cfg /usr/local/lib/texmf/tex)
	@(cd ${WRKSRC}/base; install -c -m 644 *.ist /usr/local/lib/texmf/tex)
	

.include <bsd.port.mk>
