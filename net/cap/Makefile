# New ports collection makefile for:	cap
# Date created:			09 Nov 1996
# Whom:				Masafumi NAKANE <max@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	cap
PORTVERSION=	6.0.198
PORTREVISION=	2
CATEGORIES=	net
MASTER_SITES=	ftp://munnari.OZ.AU/mac/:source \
		ftp://munnari.OZ.AU/mac/cap.patches/:patches \
		ftp://ftp.kuis.kyoto-u.ac.jp/net/cap/:source \
		ftp://ftp.kuis.kyoto-u.ac.jp/net/cap/cap60.patches/:patches
DISTFILES=	cap60.pl100.tar.Z:source \
		patches.101-126.tar.Z:patches patches.127-143.tar.Z:patches \
		patches.144-154.tar.Z:patches patches.155-162.tar.Z:patches \
		patches.163-182.tar.Z:patches patches.183-192.tar.Z:patches

PATCH_SITES=	ftp://munnari.OZ.AU/mac/cap.patches/
PATCHFILES=	cap60.patch193 cap60.patch194 cap60.patch195 cap60.patch196 \
		cap60.patch197 cap60.patch198

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Columbia AppleTalk Package for UNIX

NO_CDROM=	"Don't sell for profit"
WRKSRC=		${WRKDIR}/cap60
DIST_SUBDIR=	cap60
ALL_TARGET=	libsmade dummy-libinstall programs
INSTALL_TARGET=	include libinstall install

CFLAGS+=	-DUSESTRINGDOTH -DUSEDIRENT

USE_REINPLACE=	YES

MAN1=		AUFS.1 ash.1 atlook.1 atprint.1 cvt2apple.1 getzones.1 \
		instappl.1 snitch.1
MAN3=		CAP.3
MAN5=		atalk.local.5 etalk.local.5
MAN8=		AUFS.8 CAP.8 UAB.8 aarpd.8 atis.8 lwsrv.8 papif.8
.if !defined(NOMANCOMPRESS)
GZ=	.gz
.endif
ETC_SAMPLES=	etc/start-cap-servers extras/lib.cap.macusers \
		etc/list-cap-servers etc/kill-cap-servers \
		applications/papif/cap.printers
LIB_SAMPLES=	extras/afpfile applications/lwsrv/DBfile \
		applications/lwsrv/LWFonts applications/lwsrv/LWIIfgFonts \
		applications/lwsrv/LWPlusFonts applications/lwsrv/query.ps \
		applications/aufs/afpvols
DOCDIR=		${PREFIX}/share/doc/cap
DOCS1=		abmisc.doc asp.notes atp.notes cap.auth.doc cap.notes \
		glossary install.ms iptalk.cookbook nbp.ext pap.notes \
		print.cookbook sched.notes uab.desc.ms uar.cookbook
DOCS2=		CAP.faq CAP60.README NOTICE README
READMES=	applications/papif applications/lwsrv applications/aufs \
		doc applications support/uab support/ethertalk

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 502126
BROKEN=         "Does not compile with gcc 3.4.2"
.endif

pre-patch:
	@(cd ${WRKSRC}; \
	  for f in ../cap60.patch* ; do ${PATCH} -s -p < $$f ; done)
post-patch:
	${FIND} ${WRKSRC} -name Makefile.m4 -exec ${REINPLACE_CMD} -e 's/CFLAGS=/CFLAGS+=/' \{\} \;
	${FIND} ${WRKSRC} -name "*.[chl]" -exec ${REINPLACE_CMD} -e 's/^#\([ ]*\)endif.*/#\1endif/g' -e 's/^#\([ ]*\)else.*/#\1else/g' \{\} \;
	${GREP} -rl varargs\.h ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} -e 's/varargs\.h/stdarg\.h/g'
	${REINPLACE_CMD} -e 's/S_ISREG(&stb) == 0/access(fn, R_OK) < 0/g' ${WRKSRC}/applications/lwsrv/procset.c
	${REINPLACE_CMD} -E 's/long[ 	](clock|idletime|l|lasttime|t|timeval|tloc)([ =0]*);/time_t \1\2;/g' \
		${WRKSRC}/contrib/printqueue.c \
		${WRKSRC}/etc/nisaux.c \
		${WRKSRC}/samples/ash.c \
		${WRKSRC}/support/uab/log.c \
		${WRKSRC}/support/uab/uab.c \
		${WRKSRC}/lib/cap/ablog.c \
		${WRKSRC}/lib/cap/abpapc.c \
		${WRKSRC}/applications/lwsrv/lwsrv.c \
		${WRKSRC}/applications/aufs/aufs.c \
		${WRKSRC}/applications/papif/papif.c

pre-install:
	@${RM} -f ${WRKSRC}/libinstall

post-install:
	@${MKDIR} ${PREFIX}/etc/cap
.for f in ${ETC_SAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/etc/cap/`${BASENAME} $f`.sample
.endfor
	@${MKDIR} ${PREFIX}/lib/cap
.for f in ${LIB_SAMPLES}
	@${INSTALL_DATA} ${WRKSRC}/$f ${PREFIX}/lib/cap/`${BASENAME} $f`.sample
.endfor
.if !defined(NOPORTDOCS)
	@${ECHO_MSG} "===>  Installing relevant documentation into ${DOCDIR}."
	@${MKDIR} ${DOCDIR}
.for f in ${DOCS1}
	@${INSTALL_DATA} ${WRKSRC}/doc/$f ${DOCDIR}
.endfor
.for f in ${DOCS2}
	@${INSTALL_DATA} ${WRKSRC}/$f ${DOCDIR}
.endfor
.for f in ${READMES}
	@${INSTALL_DATA} ${WRKSRC}/$f/README ${DOCDIR}/`${BASENAME} $f`.README
.endfor
.endif
	@${ECHO_MSG} "===>  Installing manual pages."
.for sect in 1 3 5 8
.for man in ${MAN${sect}}
	@${INSTALL_MAN} ${WRKSRC}/man/${man} ${PREFIX}/man/man${sect}
.endfor
.endfor
	@${LN} -fs ${PREFIX}/man/man1/cvt2apple.1${GZ} ${PREFIX}/man/man1/cvt2cap.1${GZ}
.for f in atpinger atlooklws
	@${LN} -fs ${PREFIX}/man/man1/atlook.1${GZ} ${PREFIX}/man/man1/${f}.1${GZ}
.endfor
.for f in tlw lwpr isrv iwpr
	@${LN} -fs ${PREFIX}/man/man1/atprint.1${GZ} ${PREFIX}/man/man1/${f}.1${GZ}
.endfor
.for f in libcap libafpc libafp
	@${LN} -fs ${PREFIX}/man/man3/CAP.3${GZ} ${PREFIX}/man/man3/${f}.3${GZ}
.endfor
	@${LN} -fs ${PREFIX}/man/man8/papif.8${GZ} ${PREFIX}/man/man8/papof.8${GZ}
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
