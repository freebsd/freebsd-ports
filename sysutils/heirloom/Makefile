# Created by: Cyrille Lefevre <Cyrille.Lefevre@laposte.net>
# $FreeBSD$

PORTNAME=	heirloom
PORTVERSION=	070715
PORTREVISION=	3
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	gahr@FreeBSD.org
COMMENT=	Collection of standard Unix utilities

BUILD_DEPENDS=	ksh:${PORTSDIR}/shells/pdksh
RUN_DEPENDS:=	${BUILD_DEPENDS}

USE_BZIP2=	yes
USES=		gmake
MAKE_ARGS=	CC=${CC} CFLAGS="${CFLAGS}"
MAKEFILE=	makefile
ALL_TARGET=	#
DATADIR=	${PREFIX}/${PORTNAME}
REINPLACE_SUB=	DATADIR="${DATADIR}"

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

.if ${OSVERSION} >= 900007
EXTRA_PATCHES=	${FILESDIR}/extra-utmpx
.endif

.if ${ARCH} == "powerpc"
BROKEN=		does not compile on ${ARCH}
.endif

_MANPREFIX=	${DATADIR}/usr/share/man/5man
_MSECS=		1 1b 1m 2 3 4 5 6 7 8

_MAN1=		apropos.1 awk.1 banner.1 basename.1 bc.1 cal.1 calendar.1 \
		cat.1 chgrp.1 chmod.1 chown.1 cksum.1 cmp.1 col.1 comm.1 \
		copy.1 cp.1 cpio.1 csplit.1 cut.1 date.1 dc.1 dd.1 deroff.1 \
		df.1 diff.1 diff3.1 dirname.1 du.1 ed.1 egrep.1 env.1 \
		expand.1 expr.1 factor.1 fgrep.1 file.1 find.1 fmt.1 fold.1 \
		grep.1 groups.1 hd.1 head.1 hostname.1 id.1 intro.1 join.1 \
		line.1 listusers.1 ln.1 logins.1 logname.1 ls.1 mail.1 man.1 \
		mkdir.1 mkfifo.1 more.1 mt.1 mv.1 nawk.1 newform.1 news.1 \
		nice.1 nl.1 nohup.1 oawk.1 od.1 paste.1 pax.1 pg.1 pgrep.1 \
		pr.1 printenv.1 priocntl.1 ps.1 random.1 renice.1 rm.1 \
		rmdir.1 sdiff.1 sed.1 setpgrp.1 settime.1 sleep.1 sort.1 \
		spell.1 split.1 stty.1 su.1 sum.1 tabs.1 tail.1 tape.1 \
		tapecntl.1 tar.1 tcopy.1 tee.1 time.1 touch.1 tr.1 tsort.1 \
		tty.1 ul.1 uname.1 unexpand.1 uniq.1 units.1 uptime.1 users.1 \
		w.1 wc.1 what.1 whatis.1 who.1 whoami.1 whodo.1 xargs.1 yes.1 \
		bdiff.1 bfs.1 dircmp.1 echo.1 fmtmsg.1 getconf.1 getopt.1 kill.1 \
		mesg.1 mvdir.1 pathchk.1 printf.1 pwd.1 test.1 false.1 true.1
_MAN1B=		basename.1b chown.1b deroff.1b df.1b du.1b groups.1b echo.1b \
		install.1b ln.1b ls.1b ps.1b stty.1b sum.1b tr.1b test.1b
_MAN1M=		mknod.1m sync.1m
_MAN5=		fspec.5
_MAN7=		man.7
_MAN8=		catman.8
_M1LINKS=	df.1	dfspace.1 \
		ls.1	lc.1 \
		more.1	page.1 \
		pgrep.1	pkill.1 \

.if !defined(NO_MANCOMPRESS)
MANEXT=		.gz
.endif

.for sect in ${_MSECS:U}
. if defined(_MAN${sect})
_MANPAGES+=	${_MAN${sect}:S%^%${_MANPREFIX}/man${sect:L}/%}
. endif
. if defined(_M${sect}LINKS)
_MLINKS_PREPEND+=${_M${sect}LINKS:S%^%${_MANPREFIX}/man${sect:L}/%:S%$%${MANEXT}%}
. endif
.endfor

SH2FIX=		maninst.sh genintro.sh crossln.sh

DOC_FILES=	CHANGES LICENSE/COPYING LICENSE/LICENSE LICENSE/LUCENT \
		LICENSE/README LICENSE/COPYING.LGPL README intro.txt
#NOTE_FILES=	cp/NOTES cpio/TODO dd/NOTES grep/NOTES libuxre/NOTES \
#		more/NOTES nawk/NOTES oawk/EXPLAIN oawk/NOTES \
#		oawk/README ps/NOTES shl/NOTES tar/NOTES

post-patch:
# FreeBSD does not have neither <malloc.h> nor <alloca.h> system headers
	@${GREP} -ERl --null 'm?alloca?\.h' ${WRKSRC} | \
		${XARGS} -0 ${REINPLACE_CMD} -E '/<m?alloca?\.h>/d'
# Avoid a race (to unbreak parallel builds)
	@${REINPLACE_CMD} -e 's|htemp2|$$@.temp|g' \
		${WRKSRC}/spell/Makefile.mk

pre-configure:
	@${REINPLACE_CMD} ${REINPLACE_SUB:S/$/!g/:S/^/ -e s!%%/:S/=/%%!/} \
		${WRKSRC}/build/mk.config ${WRKSRC}/su/su.dfl.in
	@${REINPLACE_CMD} -e 's|/sbin/sh| ${SH}|' \
		${SH2FIX:S|^|${WRKSRC}/build/|}

# XXX: hack to avoid inner race (for -jX builds); should be fixed properly
# one day (e.g. by factoring out special target in the top makefile)
pre-build:
	${MAKE} -C ${WRKSRC}/libcommon -f Makefile.mk headers

post-install: compress-man install-doc

install-doc:
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}/LICENSE
. for f in ${DOC_FILES}
	@${INSTALL_DATA} ${WRKSRC}/${f} ${DOCSDIR}/${f}
. endfor
#. for file in ${NOTE_FILES}
#	@${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}/${file:T}.${file:H}
#. endfor
.endif

.include <bsd.port.mk>
