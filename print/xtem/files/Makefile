DIR=	${.CURDIR}

all: changecode hyphen_show pages_show

install: all
	${BSD_INSTALL_PROGRAM} changecode ${PREFIX}/bin
	${BSD_INSTALL_PROGRAM} hyphen_show ${PREFIX}/bin
	${BSD_INSTALL_PROGRAM} pages_show ${PREFIX}/bin
	${BSD_INSTALL_SCRIPT} xtem ${PREFIX}/bin
	${BSD_INSTALL_MAN} hyphen_show.1 ${PREFIX}/man/man1
	${BSD_INSTALL_MAN} xtem.1 ${PREFIX}/man/man1
	@echo "Installing files into ${PREFIX}/share/xtem..."
	@mkdir -p ${PREFIX}/share/xtem
	@tar -cf - . | (cd ${PREFIX}/share/xtem; \
	    tar -x --exclude-from=${DIR}/exclude-list -f -)
	@echo "Installing local files..."
	@rm -rf ${PREFIX}/share/xtem_locals_english
	@mv -f ${PREFIX}/share/xtem/locals_english.LRW ${PREFIX}/share/xtem_locals_english
	@rm -rf ${PREFIX}/share/xtem_locals_german
	@mv -f ${PREFIX}/share/xtem/locals_german.LRW ${PREFIX}/share/xtem_locals_german
	@rm -f ${PREFIX}/share/xtem/locals_english
	@ln -sf ../xtem_locals_english ${PREFIX}/share/xtem/locals_english
	@rm -f ${PREFIX}/share/xtem/locals_german
	@ln -sf ../xtem_locals_german ${PREFIX}/share/xtem/locals_german
	@echo "Fix ownership and permissions..."
	@chown -R bin:bin ${PREFIX}/share/xtem \
	    ${PREFIX}/share/xtem_locals_english \
	    ${PREFIX}/share/xtem_locals_german

