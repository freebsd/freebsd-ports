# This directory is hard-coded into the netscape binary
LIBDIR=		/usr/local/lib/netscape

BINDIR=		${PREFIX}/bin
NLSDIR=		${X11BASE}/lib/X11/nls

FILES=          LICENSE README Netscape.ad java_301

all:
	@true

install:
	-test -d ${LIBDIR} || mkdir -p ${LIBDIR}
	-test -d ${NLSDIR} || mkdir -p ${NLSDIR}
	install -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
		netscape ${BINDIR}
	install -c -m ${BINMODE} -o ${BINOWN} -g ${BINGRP} \
		movemail netscape.bin ${LIBDIR}
	install -c -m 644 -o ${BINOWN} -g ${BINGRP} \
		${FILES} ${LIBDIR}
	if [ ! -f ${LIBDIR}/mailcap ] ; then \
		install -c -m 644 -o ${BINOWN} -g ${BINGRP} mailcap ${LIBDIR}; \
	fi
	if [ ! -f ${NLSDIR}/C ] ; then \
	    install -c -m 644 -o ${BINOWN} -g ${BINGRP} nls/C ${NLSDIR}; \
	fi
	if [ ! -f ${NLSDIR}/nls.dir ] ; then \
	    install -c -m 644 -o ${BINOWN} -g ${BINGRP} nls/nls.dir ${NLSDIR}; \
	fi
