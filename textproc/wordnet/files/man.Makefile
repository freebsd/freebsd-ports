MANDIR=		${PREFIX}/man/man

MAN1=		wn.1 wnb.1 wnintro.1
MAN3=		binsrch.3 morph.3 wnintro.3 wnsearch.3 wnutil.3
MAN5=		cntlist.5 lexnames.5 senseidx.5 \
		wndb.5 wninput.5 wnintro.5
MAN7=		morphy.7 uniqbeg.7 wngloss.7 wngroups.7 wnintro.7 \
		wnlicens.7 wnpkgs.7 wnstats.7

.include <bsd.prog.mk>
