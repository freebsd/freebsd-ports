PORTNAME=	schilyutils
CATEGORIES=	sysutils converters deskutils textproc shells

COMMENT=	Collection of utilities from J. Schilling
WWW=		https://codeberg.org/schilytools/schilytools

USES+=		perl5 shebangfix
USE_PERL5=	run
SHEBANG_FILES=	cstyle/cstyle.pl

# bin/bsh bin/calc bin/copy bin/count bin/fsdiff
CONFLICTS_INSTALL=	bsh calc deforaos-browser \
		latte-integrale p5-Math-SigFigs radmind

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
		ctags \
		cut \
		fifo \
		label \
		hdump \
		lndir \
		match \
		mdigest \
		p \
		paste \
		patch \
		printf \
		sdd \
		sfind \
		sformat \
		sgrow \
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
