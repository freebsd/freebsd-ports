# New ports collection makefile for:	ump
# Date created:		15 Nov 2001
# Whom:			Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	ump
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	www
MASTER_SITES=	http://www.timidity.jp/dist/	\
		http://www.geocities.com/SiliconValley/Lab/2826/1-10/	\
		http://pubweb.bnl.gov/people/hoff/midi/1.10/	\
		${MASTER_SITE_NETSCAPE}
MASTER_SITE_SUBDIR=	sdk/plugin/unix
DISTFILES=	${BZ2DIST} ${ZDIST}

PATCH_SITES=	http://www.timidity.jp/dist/
PATCHFILES=	ump-patch-1.gz ump-patch-2.gz ump-patch-3.gz ump-patch-4.gz

MAINTAINER=	llwang@infor.org
COMMENT=	Unix MIDI Plugin based on TiMidity++

LIB_DEPENDS=	Xpm.4:${PORTSDIR}/graphics/xpm
RUN_DEPENDS=	${LOCALBASE}/bin/timidity:${PORTSDIR}/audio/timidity++	\
		${X11BASE}/bin/mozilla:${PORTSDIR}/www/mozilla

BZ2DIST=	TiMidity++-${TIMIDITY_VERSION}.tar.bz2
ZDIST=		unix-sdk-3.0b5.tar.Z ump_with_volume.tar.Z timdiffs.tar.Z

TIMIDITY_VERSION=	2.11.3

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ump
USE_GMAKE=	yes
USE_XLIB=	yes
WANT_GNOME=	yes
# CONFIGURE_ARGS+=	--enable-motif
EXTRA_PATCHES=	${.CURDIR}/../../audio/timidity++/files/*
PKGDIR=		${.CURDIR}
DIST_SUBDIR=	timidity
WRKSRC=		${WRKDIR}/TiMidity++-${TIMIDITY_VERSION}

# USE_MOTIF=	yes
# CONFIGURE_ENV=	MOTIFLIB="${MOTIFLIB}"

.include <bsd.port.pre.mk>

.if ${HAVE_GNOME:Mesound}!=""
USE_GNOME=	esound
PKGNAMESUFFIX=	-esound
CONFIGURE_ARGS+=	--enable-audio=oss,esd
.else
CONFIGURE_ARGS+=	--enable-audio=oss
.endif

.if ${PORTOBJFORMAT} == "elf"
CONFIGURE_ENV=	LDFLAGS=-export-dynamic
.endif

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@(cd ${WRKDIR} && tar -jxf ${DISTDIR}/${DIST_SUBDIR}/${BZ2DIST})
	@${MKDIR} ${WRKSRC}/ump
	@for file in ${ZDIST}; do \
		if ! (cd ${WRKSRC}/ump && tar -Zxf ${DISTDIR}/${DIST_SUBDIR}/$${file}); \
		then \
			exit 1; \
		fi \
	done

post-extract:
	@${CP} ${WRKSRC}/ump/PluginSDK30b5/include/*.h ${WRKSRC}/ump/PluginSDK30b5/common/npunix.c ${WRKSRC}/ump

post-configure:
	@${MV} ${WRKSRC}/interface/Makefile ${WRKSRC}/interface/Makefile.orig
	@${SED} -e 's^m_so_libs = $$^m_so_libs = -L${X11BASE}/lib ${MOTIFLIB} -lXt -lXext -lSM -lICE -lX11 ^' \
		-e 's^dynamic_targets = $$^dynamic_targets = interface_m.so^' \
		${WRKSRC}/interface/Makefile.orig > ${WRKSRC}/interface/Makefile
	@cd ${WRKSRC}; ${SETENV} CONFIG_HEADERS='' CONFIG_FILES=ump/Makefile ${SH} ./config.status

do-build:
	@cd ${WRKSRC}/ump; ${GMAKE} ump

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/ump/ump.so ${X11BASE}/lib/mozilla/plugins

.include <bsd.port.post.mk>
