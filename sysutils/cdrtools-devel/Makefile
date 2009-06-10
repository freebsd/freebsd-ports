# New ports collection makefile for:	cdrtools-devel
# Date created:				28 May 2003
# Whom:					marius@alchemy.franken.de
#
# $FreeBSD$
#
###########################################################################
# This makefile was contributed by Marius Strobl.
###########################################################################
# The contents of this file are subject to the terms of the
# Common Development and Distribution License, Version 1.0 only
# (the "License").  You may not use this file except in compliance
# with the License.
#
# See the file CDDL.Schily.txt in this distribution for details.
#
# When distributing Covered Code, include this CDDL HEADER in each
# file and include the License file CDDL.Schily.txt from this distribution.
###########################################################################
# The file CDDL.Schily.txt can be found in the original cdrtools tarball,
# which is mirrored at ftp://ftp.freebsd.org/pub/FreeBSD/distfiles/.
###########################################################################

PORTNAME=	cdrtools
PORTVERSION=	2.01.01a60
PORTEPOCH=	1
CATEGORIES=	sysutils audio
MASTER_SITES=	ftp://ftp.berlios.de/pub/cdrecord/alpha/ \
		ftp://ftp.cs.tu-berlin.de/pub/misc/cdrecord/alpha/

MAINTAINER=	marius@FreeBSD.org
COMMENT=	CD/DVD and ISO-9660 image creation and extraction tools

CONFLICTS=	cdrtools-[0-9]*

MAN1=		btcflash.1 cdda2wav.1 cdrecord.1 readcd.1 scgcheck.1
MAN8=		isoinfo.8 mkisofs.8
MLINKS=		isoinfo.8 devdump.8 isoinfo.8 isodump.8 isoinfo.8 isovfy.8 \
		mkisofs.8 mkhybrid.8
DOCS=		README.FreeBSD README.mkisofs
CDDA2WAVDOCS=	FAQ Frontends HOWTOUSE OtherProgs README THANKS TODO
CDRECORDDOCS=	README README.ATAPI README.DiskT@2 README.WORM README.audio \
		README.cdplus README.cdrw README.cdtext README.clone \
		README.copy README.multi README.raw README.rscsi README.sony \
		README.verify
MKISOFSDOCS=	README README.compression README.eltorito README.graft_dirs \
		README.hfs_boot README.hfs_magic README.hide README.joliet \
		README.macosx README.mkhybrid README.prep_boot README.rootinfo \
		README.session README.sort README.sparcboot README.sunx86boot
SICONVTABLES=	cp10000 cp10006 cp10007 cp10029 cp10079 cp10081 cp1250 \
		cp1251 cp1252 cp1253 cp1254 cp1255 cp1256 cp1257 cp1258 \
		cp437 cp737 cp775 cp850 cp852 cp855 cp857 cp860 cp861 \
		cp862 cp863 cp864 cp865 cp866 cp869 cp874 iso8859-1 \
		iso8859-10 iso8859-11 iso8859-13 iso8859-14 iso8859-15 \
		iso8859-16 iso8859-2 iso8859-3 iso8859-4 iso8859-5 \
		iso8859-6 iso8859-7 iso8859-8 iso8859-9 koi8-r koi8-u

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
#CFLAGS+=	-DSOURCE_MODIFIED
WRKSRC=		${WRKDIR}/${DISTNAME:C/a(.+)$//}
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes

.if defined(WITH_RSCSI)
MAN1+=		rscsi.1
PKGINSTALL=	${PKGDIR}/pkg-install.rscsi
PLIST_SUB=	RSCSI=""
PKGNAMESUFFIX=	-rscsi-devel
.else
PLIST_SUB=	RSCSI="@comment "
.endif
PKGNAMESUFFIX?=	-devel

.include <bsd.port.pre.mk>

CCOM!=		${BASENAME} ${CC}
MAKE_ENV=	CCOM=${CCOM} LANG=C INS_BASE=${LOCALBASE} INS_RBASE=${LOCALBASE}
CDRTLSTARGET=	${ARCH}-freebsd-${CCOM}

.if exists(${LOCALBASE}/lib/libiconv.a) || \
	exists(${LOCALBASE}/lib/libintl.a) || !defined(WITHOUT_NLS)
MAKE_ENV+=	OSDEFS=-I${LOCALBASE}/include
USE_GETTEXT=	yes
USE_ICONV=	yes
.endif

pre-everything::
.if !defined(WITH_RSCSI)
	@${ECHO_MSG} ""
	@${ECHO_MSG} "You may use the following build option(s):"
	@${ECHO_MSG} ""
	@${ECHO_MSG} "WITH_RSCSI=yes		builds with the rscsi daemon which provides access to"
	@${ECHO_MSG} "			local SCSI-devices over the network (the client-side"
	@${ECHO_MSG} "			in cdda2wav, cdrecord, etc. is built unconditionally)."
	@${ECHO_MSG} "			BEWARE:	The rscsi binary will be installed suid root"
	@${ECHO_MSG} "				as this is the preferred way of setting it up."
	@${ECHO_MSG} ""
.endif

post-extract:
.for i in config.guess config.sub
.for j in autoconf conf cdda2wav
	@${CP} -fp ${PORTSDIR}/Templates/${i} ${WRKSRC}/${j}
.endfor
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
.for i in DEFAULTS/Defaults.freebsd btcflash/btcflash.1 cdda2wav/cdda2wav.1 \
	cdrecord/README.rscsi cdrecord/cdrecord.1 cdrecord/cdrecord.dfl \
	include/schily/deflts.h libcdrdeflt/cdrdeflt.c librscg/scsi-remote.c \
	readcd/readcd.1 rscsi/rscsi.1 rscsi/rscsi.c rscsi/rscsi.dfl \
	scgcheck/scgcheck.1
	@${REINPLACE_CMD} -e 's|\/opt\/schily|${PREFIX}|g; \
		s|\/usr\/local|${PREFIX}|g; s|\/etc\/default|${PREFIX}\/etc|g; \
		s|\/var\/adm\/messages|\/var\/run\/dmesg.boot|g' ${WRKSRC}/${i}
.endfor
	@${MV} -f ${WRKSRC}/libparanoia/cdda_paranoia.h \
		${WRKSRC}/libparanoia/js_cdda_paranoia.h
.for i in cdda2wav/cdda2wav.c cdda2wav/global.h libparanoia/gap.c \
	libparanoia/overlap.c libparanoia/p_block.c libparanoia/paranoia.c
	@${REINPLACE_CMD} -e 's|cdda_paranoia\.h|js_cdda_paranoia.h|g' \
		${WRKSRC}/${i}
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
.if defined(WITH_RSCSI)
	@${INSTALL_MAN} ${WRKSRC}/rscsi/rscsi.1 ${PREFIX}/man/man1
.endif
	@${INSTALL_MAN} ${WRKSRC}/scgcheck/scgcheck.1 ${PREFIX}/man/man1
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${PREFIX}/man/man8
	@${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 ${PREFIX}/man/man8
	@${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl \
		${PREFIX}/etc/cdrecord.sample
.if !exists(${PREFIX}/etc/cdrecord)
	@${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl ${PREFIX}/etc/cdrecord
.endif
	@${MKDIR} ${PREFIX}/lib/siconv
.for i in ${SICONVTABLES}
	@${INSTALL_DATA} ${WRKSRC}/libsiconv/tables/${i} ${PREFIX}/lib/siconv
.endfor
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
	@${MKDIR} ${DOCSDIR}/cdrecord
.for i in ${CDRECORDDOCS}
	@${INSTALL_DATA} ${WRKSRC}/cdrecord/${i} ${DOCSDIR}/cdrecord
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
