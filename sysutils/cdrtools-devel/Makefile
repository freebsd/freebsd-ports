# New ports collection makefile for:	cdrtools-devel
# Date created:				28 May 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#

PORTNAME=	cdrtools
PORTVERSION=	2.01.01a09
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/alpha/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	CD/CD-R[W] and ISO-9660 image creation and extraction tools

CONFLICTS=	cdrtools-[0-9]*

MAN1=		btcflash.1 cdda2wav.1 cdrecord.1 readcd.1 scgcheck.1
MAN8=		isoinfo.8 mkisofs.8
MLINKS=		isoinfo.8 devdump.8 isoinfo.8 isodump.8 isoinfo.8 isovfy.8 \
		mkisofs.8 mkhybrid.8
DOCS=		README README.ATAPI README.DiskT@2 README.FreeBSD README.WORM \
		README.audio README.cdplus README.cdrw README.cdtext \
		README.clone README.copy README.mkisofs README.multi \
		README.raw README.rscsi README.sony README.verify
CDDA2WAVDOCS=	FAQ Frontends HOWTOUSE OtherProgs README THANKS TODO
MKISOFSDOCS=	README README.compression README.eltorito README.graft_dirs \
		README.hfs_boot README.hfs_magic README.hide README.joliet \
		README.macosx README.mkhybrid README.prep_boot README.rootinfo \
		README.session README.sort README.sparcboot README.sunx86boot

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
#CFLAGS+=	-DSOURCE_MODIFIED
WRKSRC=		${WRKDIR}/${DISTNAME:C/a(.+)$//}
SUB_FILES=	pkg-message

.if defined(WITH_RSCSI)
PKGINSTALL=	${PKGDIR}/pkg-install.rscsi
PLIST_SUB=	RSCSI=""
PKGNAMESUFFIX=	-rscsi-devel
.else
PLIST_SUB=	RSCSI="@comment "
.endif
PKGNAMESUFFIX?=	-devel

.include <bsd.port.pre.mk>

CCOM!=		${BASENAME} ${CC}
MAKE_ENV=	CCOM=${CCOM} LANG=C
CDRTLSTARGET=	${ARCH}-freebsd-${CCOM}

.if ${OSVERSION} >= 501104 && ${OSVERSION} < 502113
IGNORE=		does not work with mlockall(2) on your version of FreeBSD 5.x. Please update to FreeBSD 5.3 or later in order to use this port
.endif

.if exists(${LOCALBASE}/lib/libcdio.a) || defined(WITH_CDDB)
WITH_CDDB=	yes
LIB_DEPENDS+=	cddb.3:${PORTSDIR}/audio/libcddb \
		cdio.6:${PORTSDIR}/sysutils/libcdio
.endif

pre-everything::
.if !defined(WITH_RSCSI)
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
.if !defined(WITH_CDDB)
	@${ECHO_MSG} "WITH_CDDB=yes		builds with cddb (http://freedb.org) support"
	@${ECHO_MSG} ""
.endif

post-extract:
.for i in config.guess config.sub
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/conf
	@${CP} ${PORTSDIR}/Templates/${i} ${WRKSRC}/cdda2wav
.endfor
.if ${CDRTLSTARGET} != "i386-freebsd-cc"
	@${LN} -sf ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${CDRTLSTARGET}.rul
.endif

post-patch:
	@${RM} ${WRKSRC}/TARGETS/55scgskeleton ${WRKSRC}/TARGETS/85man
.if !defined(WITH_RSCSI)
	@${RM} ${WRKSRC}/TARGETS/55rscsi
.endif
.for i in README.rscsi btcflash/btcflash.1 cdda2wav/cdda2wav.1 \
	cdrecord/cdrecord.1 cdrecord/cdrecord.dfl cdrecord/defaults.c \
	include/deflts.h librscg/scsi-remote.c readcd/readcd.1 \
	rscsi/rscsi.c rscsi/rscsi.dfl scgcheck/scgcheck.1
	@${REINPLACE_CMD} -e 's|\/opt\/schily|${PREFIX}|g; \
		s|\/usr\/local|${PREFIX}|g; s|\/etc\/default|${PREFIX}\/etc|g; \
		s|\/var\/adm\/messages|\/var\/run\/dmesg.boot|g' ${WRKSRC}/${i}
.endfor
#	@${REINPLACE_CMD} -E -e \
#		's|#define.+INSERT_YOUR_EMAIL_ADDRESS_HERE|& "${MAINTAINER}"|' \
#		${WRKSRC}/cdrecord/cdrecord.c

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/btcflash/OBJ/${CDRTLSTARGET}/btcflash \
		${PREFIX}/bin
	@${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/${CDRTLSTARGET}/cdda2wav \
		${PREFIX}/bin
	@${LN} -sf cdda2wav ${PREFIX}/bin/list_audio_tracks
	@${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${CDRTLSTARGET}/cdrecord \
		${PREFIX}/bin
.for i in devdump isodebug isodump isoinfo isovfy
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${CDRTLSTARGET}/${i} \
		${PREFIX}/bin
.endfor
	@${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${CDRTLSTARGET}/mkisofs \
		${PREFIX}/bin
	@${LN} -sf mkisofs ${PREFIX}/bin/mkhybrid
	@${INSTALL_PROGRAM} ${WRKSRC}/readcd/OBJ/${CDRTLSTARGET}/readcd \
		${PREFIX}/bin
.if defined(WITH_RSCSI)
	@${INSTALL_PROGRAM} ${WRKSRC}/rscsi/OBJ/${CDRTLSTARGET}/rscsi \
		${PREFIX}/sbin
	@${CHMOD} u+s ${PREFIX}/sbin/rscsi
.endif
	@${INSTALL_PROGRAM} ${WRKSRC}/scgcheck/OBJ/${CDRTLSTARGET}/scgcheck \
		${PREFIX}/bin
	@${INSTALL_MAN} ${WRKSRC}/btcflash/btcflash.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/readcd/readcd.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/scgcheck/scgcheck.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8
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
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${DOCS}
	@${INSTALL_DATA} ${WRKSRC}/${i} ${DOCSDIR}
.endfor
	@${MKDIR} ${DOCSDIR}/cdda2wav
.for i in ${CDDA2WAVDOCS}
	@${INSTALL_DATA} ${WRKSRC}/cdda2wav/${i} ${DOCSDIR}/cdda2wav
.endfor
	@${MKDIR} ${DOCSDIR}/mkisofs
.for i in ${MKISOFSDOCS}
	@${INSTALL_DATA} ${WRKSRC}/mkisofs/${i} ${DOCSDIR}/mkisofs
.endfor
.endif

post-install:
	-@if [ -f ${PKGINSTALL} ]; then ${SETENV} PKG_PREFIX=${PREFIX} \
		${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL; fi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
