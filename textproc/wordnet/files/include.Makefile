WN_INSTALLDIR = ${PREFIX}/include/WordNet-${VER}

WN_FILES=	license.h setutil.h wn.h wnconsts.h wnglobal.h \
		wnhelp.h wnrtl.h wntypes.h

all: $(WN_FILES)

${WN_INSTALLDIR}:
	mkdir -p ${WN_INSTALLDIR}

install: ${WN_INSTALLDIR}
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} -m 444 \
		${WN_FILES} ${WN_INSTALLDIR}/

NOOBJ=		noobj

.include <bsd.prog.mk>
