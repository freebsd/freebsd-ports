PORTNAME=	schilyutils
CATEGORIES=	sysutils converters deskutils textproc shells

COMMENT=	Collection of utilities from J. Schilling

USES+=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	man2html/man2html cstyle/cstyle.pl

CONFLICTS_INSTALL=	bosh-cli bsh calc clusterit deforaos-browser heirloom-sh latte-integrale p5-Math-SigFigs radmind # bin/bosh bin/bsh bin/calc bin/copy bin/count bin/fsdiff bin/jsh

MASTERDIR=	${.CURDIR}/../../devel/schilybase
COMPONENTS=	bsh \
		btcflash \
		cal \
		calc \
		calltree \
		change \
		compare \
		copy \
		count \
		cpp \
		cstyle \
		cut \
		fifo \
		label \
		hdump \
		lndir \
		match \
		mdigest \
		obosh \
		p \
		paste \
		patch \
		pbosh \
		printf \
		sdd \
		sfind \
		sformat \
		sgrow \
		sh \
		termcap \
		translit \
		udiff

# these files are installed by the patch target,
# but they belong to devel/sccs.
post-install:
	${RM} ${STAGEDIR}${PREFIX}/ccs/bin/sccspatch
	cd ${STAGEDIR}${PREFIX} && ${RMDIR} -p ccs/bin
	${RM} ${STAGEDIR}${PREFIX}/share/man/man1/sccspatch.1

.include "${MASTERDIR}/Makefile.master"
