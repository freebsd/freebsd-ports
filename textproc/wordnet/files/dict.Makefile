WN_INSTALLDIR=	${STAGEDIR}${PREFIX}/share/WordNet
WN_FILES=	adj.exc adv.exc cntlist cntlist.rev data.adj \
		data.adv data.noun data.verb frames.vrb index.adj \
		index.adv index.noun index.sense index.verb \
		noun.exc sentidx.vrb sents.vrb verb.Framestext verb.exc

all: $(WN_FILES)

${WN_INSTALLDIR}:
	mkdir -p ${WN_INSTALLDIR}

.for f in ${WN_FILES}
INSTALLED+=	${WN_INSTALLDIR}/$f

${WN_INSTALLDIR}/$f: $f
	${BSD_INSTALL_DATA} $f ${WN_INSTALLDIR}/$f
.endfor

install: ${WN_INSTALLDIR} ${INSTALLED}

NO_OBJ=  noobj
.include <bsd.prog.mk>
