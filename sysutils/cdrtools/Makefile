# Created by: Dirk Froemberg <dirk@FreeBSD.org>
# $FreeBSD$

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
PORTVERSION=	3.01
CATEGORIES=	sysutils audio
MASTER_SITES=	SF/${PORTNAME}

MAINTAINER=	marius@FreeBSD.org
COMMENT=	CD/DVD/BluRay and ISO-9660 image creation and extraction tools

LICENSE=	BSD2CLAUSE CDDL GPLv2 LGPL21
LICENSE_COMB=	multi

CONFLICTS=	cdrkit-* cdrtools-devel-* cjk-cdrtools-*

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

USES=		gmake tar:bzip2
#CFLAGS+=	-DSOURCE_MODIFIED
SUB_FILES=	pkg-message
MAKE_JOBS_UNSAFE=	yes

OPTIONS_DEFINE=	CDDA2MP3 CDDA2OGG DOCS NLS RSCSI

CDDA2MP3_DESC=	Build cdda2mp3 (requires audio/lame)
CDDA2OGG_DESC=	Build cdda2ogg (requires audio/vorbis-tools)
RSCSI_DESC=	Build rscsi suid root remote SCSI access daemon

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCDDA2MP3}
PLIST_SUB+=	CDDA2MP3=""
RUN_DEPENDS+=	lame:audio/lame
.else
PLIST_SUB+=	CDDA2MP3="@comment "
.endif
.if ${PORT_OPTIONS:MCDDA2OGG}
PLIST_SUB+=	CDDA2OGG=""
RUN_DEPENDS+=	oggenc:audio/vorbis-tools
.else
PLIST_SUB+=	CDDA2OGG="@comment "
.endif
.if ${PORT_OPTIONS:MRSCSI}
PKGINSTALL=	${PKGDIR}/pkg-install.rscsi
PLIST_SUB+=	RSCSI=""
PKGNAMESUFFIX=	-rscsi
.else
PLIST_SUB+=	RSCSI="@comment "
.endif

MAKE_ENV=	CCOM=cc GMAKE_NOWARN=true INS_BASE=${LOCALBASE} \
		INS_RBASE=${LOCALBASE}
CDRTLSTARGET=	${ARCH}-${OPSYS:tl}-cc
CDRTLSXARCH!=	${UNAME} -m

.if exists(/usr/include/iconv.h)
USES+=		iconv
.endif
.if exists(${LOCALBASE}/lib/libiconv.a) || \
	exists(${LOCALBASE}/lib/libintl.a) || ${PORT_OPTIONS:MNLS}
MAKE_ENV+=	DEFOSINCDIRS=${LOCALBASE}/include LDPATH=-L${LOCALBASE}/lib
USES+=		gettext iconv
.endif

post-extract:
.for i in config.guess config.sub
.for j in autoconf conf cdda2wav
	@${CP} -fp ${PORTSDIR}/Templates/${i} ${WRKSRC}/${j}
.endfor
.endfor
.if ${CDRTLSXARCH} != "i386"
	@${LN} -sf ${WRKSRC}/RULES/i386-freebsd-cc.rul \
		${WRKSRC}/RULES/${CDRTLSXARCH}-${OPSYS:tl}-cc.rul
.endif

post-patch:
	@${RM} ${WRKSRC}/TARGETS/55scgskeleton ${WRKSRC}/TARGETS/85man
.if !${PORT_OPTIONS:MRSCSI}
	@${RM} ${WRKSRC}/TARGETS/55rscsi
.endif
.for i in btcflash/btcflash.1 cdda2wav/cdda2mp3 cdda2wav/cdda2ogg \
	cdda2wav/cdda2ogg.1 cdda2wav/cdda2wav.1 cdrecord/README.rscsi \
	cdrecord/cdrecord.1 cdrecord/cdrecord.dfl include/schily/deflts.h \
	libcdrdeflt/cdrdeflt.c librscg/scsi-remote.c readcd/readcd.1 \
	rscsi/rscsi.1 rscsi/rscsi.c rscsi/rscsi.dfl scgcheck/scgcheck.1
	@${REINPLACE_CMD} -e 's|\/opt\/schily|${PREFIX}|g; \
		s|\/usr\/local|${PREFIX}|g; s|\/etc\/default|${PREFIX}\/etc|g; \
		s|\/var\/adm\/messages|\/var\/run\/dmesg.boot|g; \
		s|^CDDA2WAV=|&${PREFIX}\/bin\/|g; \
		s|^MP_CODER=|&${LOCALBASE}\/bin\/|g' ${WRKSRC}/${i}
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
	${INSTALL_PROGRAM} ${WRKSRC}/btcflash/OBJ/${CDRTLSTARGET}/btcflash \
		${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MCDDA2MP3}
	${INSTALL_SCRIPT} ${WRKSRC}/cdda2wav/cdda2mp3 ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2ogg.1 \
		${STAGEDIR}${PREFIX}/man/man1/cdda2mp3.1
.endif
.if ${PORT_OPTIONS:MCDDA2OGG}
	${INSTALL_SCRIPT} ${WRKSRC}/cdda2wav/cdda2ogg ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2ogg.1 \
		${STAGEDIR}${PREFIX}/man/man1
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/cdda2wav/OBJ/${CDRTLSTARGET}/cdda2wav \
		${STAGEDIR}${PREFIX}/bin
	${LN} -sf cdda2wav ${STAGEDIR}${PREFIX}/bin/list_audio_tracks
	${INSTALL_PROGRAM} ${WRKSRC}/cdrecord/OBJ/${CDRTLSTARGET}/cdrecord \
		${STAGEDIR}${PREFIX}/bin
.for i in devdump isodebug isodump isoinfo isovfy
	${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/diag/OBJ/${CDRTLSTARGET}/${i} \
		${STAGEDIR}${PREFIX}/bin
.endfor
	${INSTALL_PROGRAM} ${WRKSRC}/mkisofs/OBJ/${CDRTLSTARGET}/mkisofs \
		${STAGEDIR}${PREFIX}/bin
	${LN} -sf mkisofs ${STAGEDIR}${PREFIX}/bin/mkhybrid
	${INSTALL_PROGRAM} ${WRKSRC}/readcd/OBJ/${CDRTLSTARGET}/readcd \
		${STAGEDIR}${PREFIX}/bin
.if ${PORT_OPTIONS:MRSCSI}
	${INSTALL_PROGRAM} ${WRKSRC}/rscsi/OBJ/${CDRTLSTARGET}/rscsi \
		${STAGEDIR}${PREFIX}/sbin
.endif
	${INSTALL_PROGRAM} ${WRKSRC}/scgcheck/OBJ/${CDRTLSTARGET}/scgcheck \
		${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/btcflash/btcflash.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cdda2wav/cdda2wav.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/cdrecord/cdrecord.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/readcd/readcd.1 ${STAGEDIR}${PREFIX}/man/man1
.if ${PORT_OPTIONS:MRSCSI}
	@${INSTALL_MAN} ${WRKSRC}/rscsi/rscsi.1 ${STAGEDIR}${PREFIX}/man/man1
.endif
	${INSTALL_MAN} ${WRKSRC}/scgcheck/scgcheck.1 \
		${STAGEDIR}${PREFIX}/man/man1
	${INSTALL_MAN} ${WRKSRC}/mkisofs/mkisofs.8 ${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_MAN} ${WRKSRC}/mkisofs/diag/isoinfo.8 \
		${STAGEDIR}${PREFIX}/man/man8
	${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl \
		${STAGEDIR}${PREFIX}/etc/cdrecord.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/cdrecord)
	${INSTALL_DATA} ${WRKSRC}/cdrecord/cdrecord.dfl \
		${STAGEDIR}${PREFIX}/etc/cdrecord
.endif
	${MKDIR} ${STAGEDIR}${PREFIX}/lib/siconv
.for i in ${SICONVTABLES}
	${INSTALL_DATA} ${WRKSRC}/libsiconv/tables/${i} \
		${STAGEDIR}${PREFIX}/lib/siconv
.endfor
.if ${PORT_OPTIONS:MRSCSI}
	${INSTALL_DATA} ${WRKSRC}/rscsi/rscsi.dfl \
		${STAGEDIR}${PREFIX}/etc/rscsi.sample
.if !exists(${STAGEDIR}${PREFIX}/etc/rscsi)
	${INSTALL_DATA} ${WRKSRC}/rscsi/rscsi.dfl ${STAGEDIR}${PREFIX}/etc/rscsi
.endif
.endif
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${DOCS}
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/cdda2wav
.for i in ${CDDA2WAVDOCS}
	${INSTALL_DATA} ${WRKSRC}/cdda2wav/${i} ${STAGEDIR}${DOCSDIR}/cdda2wav
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/cdrecord
.for i in ${CDRECORDDOCS}
	${INSTALL_DATA} ${WRKSRC}/cdrecord/${i} ${STAGEDIR}${DOCSDIR}/cdrecord
.endfor
	${MKDIR} ${STAGEDIR}${DOCSDIR}/mkisofs
.for i in ${MKISOFSDOCS}
	${INSTALL_DATA} ${WRKSRC}/mkisofs/${i} ${STAGEDIR}${DOCSDIR}/mkisofs
.endfor

.include <bsd.port.mk>
