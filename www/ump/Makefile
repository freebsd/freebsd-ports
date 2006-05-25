# New ports collection makefile for:	ump
# Date created:		15 Nov 2001
# Whom:			Leland Wang <llwang@infor.org>
#
# $FreeBSD$
#

PORTNAME=	ump
PORTVERSION=	1.10
PORTREVISION=	8
CATEGORIES=	www
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE:S/$/:timidity/} \
		http://www.geocities.com/SiliconValley/Lab/2826/1-10/:ump \
		http://pubweb.bnl.gov/people/hoff/midi/1.10/:ump \
		${MASTER_SITE_NETSCAPE:S/$/:plugin/}
MASTER_SITE_SUBDIR=	timidity/:timidity \
		sdk/plugin/unix/:plugin
DISTFILES=	${BZ2DIST} ${ZDIST}
EXTRACT_ONLY=	${BZ2DIST:C/:.*$//}

PATCH_SITES=	http://www.onicos.com/staff/iz/timidity/dist/
PATCHFILES=	ump-patch-1.gz ump-patch-2.gz ump-patch-3.gz ump-patch-4.gz

MAINTAINER=	llwang@infor.org
COMMENT=	Unix MIDI Plugin based on TiMidity++

LIB_DEPENDS=	arc:${PORTSDIR}/archivers/libarc
RUN_DEPENDS=	${LOCALBASE}/share/timidity/timidity.cfg:${PORTSDIR}/audio/eawpats

LATEST_LINK=	UNIXMidiPlugin
CONFLICTS=	ump-0.8.[0-9]*

BZ2DIST=	TiMidity++-${TIMIDITY_VERSION}.tar.bz2:timidity
ZDIST=		unix-sdk-3.0b5.tar.Z:plugin ump_with_volume.tar.Z:ump timdiffs.tar.Z:ump

TIMIDITY_VERSION=	2.13.2

USE_BZIP2=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-ump --with-default-path=${LOCALBASE}/share/timidity
USE_GMAKE=	yes
USE_X_PREFIX=	yes
USE_XPM=	yes
WANT_GNOME=	yes
# CONFIGURE_ARGS+=	--enable-motif
EXTRA_PATCHES=	${PORTSDIR}/audio/timidity++/files/*
PKGDIR=		${.CURDIR}
WRKSRC=		${WRKDIR}/TiMidity++-${TIMIDITY_VERSION}
BUILD_WRKSRC=	${WRKSRC}/ump
EXTRACT_AFTER_ARGS=	| ${TAR} -xpf - --exclude '*/libarc/*'	\
	--exclude '*/utils/mblock.h' --exclude '*/utils/memb.h'
ALL_TARGET=	ump

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

post-extract:
	@${MKDIR} ${WRKSRC}/ump
	@for f in ${ZDIST:C/:.*$//}; do \
		if ! (cd ${WRKSRC}/ump && tar -Zxf ${DISTDIR}/${DIST_SUBDIR}/$${f}); \
		then \
			exit 1; \
		fi \
	done
	@${CP} ${WRKSRC}/ump/PluginSDK30b5/include/*.h ${WRKSRC}/ump/PluginSDK30b5/common/npunix.c ${WRKSRC}/ump

post-configure:
	@${MV} ${WRKSRC}/interface/Makefile ${WRKSRC}/interface/Makefile.orig
	@${SED} -e 's^m_so_libs = $$^m_so_libs = -L${X11BASE}/lib ${MOTIFLIB} -lXt -lXext -lSM -lICE -lX11 ^' \
		-e 's^dynamic_targets = $$^dynamic_targets = interface_m.so^' \
		${WRKSRC}/interface/Makefile.orig > ${WRKSRC}/interface/Makefile
	@cd ${WRKSRC}; ${SETENV} CONFIG_HEADERS='' CONFIG_FILES=ump/Makefile ${SH} ./config.status

do-install:
	${MKDIR} ${PREFIX}/lib/browser_plugins
	${INSTALL_PROGRAM} ${WRKSRC}/ump/ump.so ${PREFIX}/lib/browser_plugins

.include <bsd.port.post.mk>
