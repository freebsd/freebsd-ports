# New ports collection makefile for:	cdrtools-devel
# Date created:				28 May 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME?=	cdrtools
CDRTLSVERSION=	2.01a25
PORTVERSION?=	${CDRTLSVERSION}
PORTREVISION?=	1
CATEGORIES?=	sysutils audio
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/alpha/
DISTNAME=	cdrtools-${CDRTLSVERSION}

MAINTAINER=	marius@alchemy.franken.de
COMMENT?=	Cdrecord and other programs to extract and record CDs/CD-R[W]s

CONFLICTS?=	cdrtools-[0-9]*

.if defined(MKISOFS)
MAN8=		isoinfo.8 mkisofs.8
MLINKS=		isoinfo.8 devdump.8 isoinfo.8 isodump.8 isoinfo.8 isovfy.8 \
		mkisofs.8 mkhybrid.8
DOCS=		README README.compression README.eltorito README.graft_dirs \
		README.hfs_boot README.hfs_magic README.hide README.joliet \
		README.macosx README.mkhybrid README.prep_boot README.rootinfo \
		README.session README.sort README.sparcboot README.sunx86boot
.else
MAN1=		cdda2wav.1 cdrecord.1 readcd.1 scgcheck.1
DOCS=		README README.DiskT@2 README.FreeBSD README.WORM README.audio \
		README.cdplus README.cdrw README.cdtext README.clone \
		README.copy README.mkisofs README.multi README.raw \
		README.rscsi README.sony README.verify
CDDA2WAVDOCS=	FAQ Frontends HOWTOUSE OtherProgs README THANKS TODO
.endif

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
MAKE_ENV=	CCOM=${CC}
CFLAGS+=	-DSOURCE_MODIFIED
WRKSRC=		${WRKDIR}/${DISTNAME:C/a(.+)$//}

.if defined(MKISOFS)
DOCSSRC=	${WRKSRC}/${PORTNAME}
PKGMESSAGE=	""
.else
DOCSSRC=	${WRKSRC}
PKGMESSAGE=	${WRKDIR}/pkg-message
.if defined(WITH_RSCSI)
PKGINSTALL=	${PKGDIR}/pkg-install.rscsi
PLIST_SUB=	RSCSI=""
PKGNAMESUFFIX=	-rscsi-devel
.else
PLIST_SUB=	RSCSI="@comment "
.endif
.endif
PKGNAMESUFFIX?=	-devel

.include <bsd.port.pre.mk>

pre-everything::
.if !defined(MKISOFS) && !defined(WITH_RSCSI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_RSCSI=yes		builds with the rscsi daemon which provides access to"
	@${ECHO_MSG} "			local SCSI-devices over the network (the client-side"
	@${ECHO_MSG} "			in cdda2wav, cdrecord, etc. is built unconditionally)."
	@${ECHO_MSG} "			BEWARE:	The rscsi binary gets installed suid root as"
	@${ECHO_MSG} "				this is the preferred method to set it up."
	@${ECHO_MSG} ""
.endif

post-extract:
.for i in config.guess config.sub
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/conf
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/cdda2wav
.endfor
.if ${MACHINE_ARCH} != "i386" || ${CC} != "cc"
	@${LN} -sf ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${MACHINE_ARCH}-freebsd-${CC}.rul
.endif

post-patch:
.if defined(MKISOFS)
.for i in 45libdeflt 45libedc 45libparanoia 55cdda2wav 55cdrecord 55readcd \
	55rscsi 55scgcheck
	@${RM} ${WRKSRC}/TARGETS/${i}
.endfor
.else
.for i in 45libfile 45libhfs_iso 45libunls 55mkisofs 55mkisofs!@!diag
	@${RM} ${WRKSRC}/TARGETS/${i}
.endfor
.if !defined(WITH_RSCSI)
	@${RM} ${WRKSRC}/TARGETS/55rscsi
.endif
.for i in README.rscsi include/deflts.h cdda2wav/cdda2wav.1 \
	cdrecord/cdrecord.1 cdrecord/cdrecord.dfl cdrecord/defaults.c \
	readcd/readcd.1 rscsi/rscsi.c rscsi/rscsi.dfl scgcheck/scgcheck.1
	@${REINPLACE_CMD} -e 's|\/opt\/schily|${PREFIX}|g; \
		s|\/usr\/local|${PREFIX}|g; s|\/etc\/default|${PREFIX}\/etc|g; \
		s|\/var\/adm\/messages|\/var\/run\/dmesg.boot|g' ${WRKSRC}/${i}
.endfor
	@${REINPLACE_CMD} -E -e \
		's|#define.+INSERT_YOUR_EMAIL_ADDRESS_HERE|& "${MAINTAINER}"|' \
		${WRKSRC}/cdrecord/cdrecord.c
	@${SED} 's|%%PREFIX%%|${PREFIX}|g' ${PKGDIR}/pkg-message > \
		${WRKDIR}/pkg-message
.endif

do-install:
.if defined(MKISOFS)
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${ARCH}-freebsd-cc/mkisofs \
		${PREFIX}/bin
	@${LN} -sf mkisofs ${PREFIX}/bin/mkhybrid
.for i in devdump isodebug isodump isoinfo isovfy
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${ARCH}-freebsd-cc/${i} \
		${PREFIX}/bin
.endfor
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8
.else
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/${ARCH}-freebsd-cc/cdda2wav \
		${PREFIX}/bin
	@${LN} -sf cdda2wav ${PREFIX}/bin/list_audio_tracks
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${ARCH}-freebsd-cc/cdrecord \
		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/readcd/OBJ/${ARCH}-freebsd-cc/readcd \
		${PREFIX}/bin
.if defined(WITH_RSCSI)
	@${INSTALL_PROGRAM} ${WRKSRC}/rscsi/OBJ/${ARCH}-freebsd-cc/rscsi \
		${PREFIX}/sbin
	@${CHMOD} u+s ${PREFIX}/sbin/rscsi
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/scgcheck/OBJ/${ARCH}-freebsd-cc/scgcheck \
		${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/readcd/readcd.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/scgcheck/scgcheck.1 ${PREFIX}/man/man1
	@${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl \
		${PREFIX}/etc/cdrecord.sample
.if !exists(${PREFIX}/etc/cdrecord)
	@${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl ${PREFIX}/etc/cdrecord
.endif
.if defined(WITH_RSCSI)
	@${INSTALL_DATA} ${WRKSRC}/rscsi/rscsi.dfl ${PREFIX}/etc/rscsi.sample
.if !exists(${PREFIX}/etc/rscsi)
	@${INSTALL_DATA} ${WRKSRC}/rscsi/rscsi.dfl ${PREFIX}/etc/rscsi
.endif
.endif
.endif
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${DOCSSRC}/${i} ${DOCSDIR}
.endfor
.if !defined(MKISOFS)
	@${MKDIR} ${DOCSDIR}/cdda2wav
.for i in ${CDDA2WAVDOCS}
	@${INSTALL_DATA} ${DOCSSRC}/cdda2wav/${i} ${DOCSDIR}/cdda2wav
.endfor
.endif
.endif

post-install:
	-@if [ -f ${PKGINSTALL} ]; then ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; fi
	@if [ -f ${WRKDIR}/pkg-message ]; then ${CAT} ${WRKDIR}/pkg-message; fi

.include <bsd.port.post.mk>
