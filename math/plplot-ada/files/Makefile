all: build

build:
	gnatmake -p -P build_plplot

install:
	mkdir -p ${DESTDIR}${PREFIX}/lib/gnat \
		 ${DESTDIR}${PREFIX}/lib/plplotada \
		 ${DESTDIR}${PREFIX}/include/plplotada
	${BSD_INSTALL_DATA} ada/build/lib/libplplotada.a \
		${DESTDIR}${PREFIX}/lib/plplotada
	${BSD_INSTALL_DATA} ada/build/lib/*.ali \
		${DESTDIR}${PREFIX}/lib/plplotada
	${BSD_INSTALL_DATA} plplot.gpr \
		${DESTDIR}${PREFIX}/lib/gnat
	${BSD_INSTALL_DATA} ada/*.ad[bs] \
		${DESTDIR}${PREFIX}/include/plplotada
