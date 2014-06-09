WN_INSTALLDIR = ${STAGEDIR}${PREFIX}/include/WordNet

WN_FILES=	wn.h wngrind.h

all: $(WN_FILES)

${WN_INSTALLDIR}:
	mkdir -p ${WN_INSTALLDIR}

install: ${WN_INSTALLDIR}
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WN_FILES} ${WN_INSTALLDIR}/

NO_OBJ=		noobj

.include <bsd.prog.mk>
