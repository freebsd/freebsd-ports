WN_INSTALLDIR=	${PREFIX}/share/WordNet-${VER}
WN_FILES=	data.noun data.verb data.adj data.adv index.noun \
		index.verb index.adj index.adv noun.exc verb.exc \
		adj.exc adv.exc index.sense cntlist.rev \
		cntlist lexnames sentidx.vrb sents.vrb

all: $(WN_FILES)

${WN_INSTALLDIR}:
	mkdir -p ${WN_INSTALLDIR}

.for f in ${WN_FILES}
INSTALLED+=	${WN_INSTALLDIR}/$f

${WN_INSTALLDIR}/$f: $f
	${INSTALL} -C -o ${BINOWN} -g ${BINGRP} \
		$f ${WN_INSTALLDIR}/$f
.endfor

install: ${WN_INSTALLDIR} ${INSTALLED}

NOOBJ=  noobj
.include <bsd.prog.mk>
