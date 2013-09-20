# Created by: Alex de Kruijff
# $FreeBSD$

PORTNAME=	samesame
PORTVERSION=	1.10
CATEGORIES=	sysutils
MASTER_SITES=	http://samesame.kruijff.org/ \
		${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	dhn

MAINTAINER=	samesame@akruijff.dds.nl
COMMENT=	Find duplicate files and optionally link them together

CONFLICTS=	samefile-[0-9]*

MAN1=	samesame.1 samearchive.1 samearchive-lite.1 samefile.1 sameln.1 \
	samecp.1 samemv.1 samerm.1 samechflags.1 samechmod.1 samechown.1 \
	samedelay.1
MANCOMPRESSED=	no

PLIST_FILES=	bin/samearchive		bin/samefile 	bin/samecp \
		bin/samearchive-lite	bin/sameln 	bin/samemv \
		bin/samechflags		bin/samerm	bin/samechmod \
		bin/samechown		bin/samedelay

HAS_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-samechflags --enable-samechmod \
		--mandir="${MANPREFIX}/man" --prefix="${PREFIX}" \
		--includedir="${LOCALBASE}/include" --libdir="${LOCALBASE}/lib"
USE_BZIP2=	yes

OPTIONS_DEFINE=	DEBUG DISK_STORAGE LOW_MEMORY_PROFILE EXPERIMENTAL PROFILER TEST
DISK_STORAGE_DESC=		Allows temporarily storage on disk
LOW_MEMORY_PROFILE_DESC=	Low memory profile reduces functionality
EXPERIMENTAL_DESC=		Enables experimental functionality
PROFILER_DESC=			Enables gprof support
TEST_DESC=			Run quality assurance test

NO_STAGE=	yes
.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG}
CONFIGURE_ARGS+=	--enable-debug
.endif

.if ${PORT_OPTIONS:MDISK_STORAGE}
CONFIGURE_ARGS+=	--enable-disk-storage
PLIST_FILES+=		etc/rc.d/samesame.sh
.endif

.if ${PORT_OPTIONS:MEXPERIMENTAL}
CONFIGURE_ARGS+=	--enable-experimental --enable-fsort
#CONFIGURE_ARGS+=	--enable-checksums --enable-preread
PLIST_FILES+=		bin/fsort
.endif

.if ${PORT_OPTIONS:MLOW_MEMORY_PROFILE}
CONFIGURE_ARGS+=	--enable-low-memory-profile --disable-read-onces
.endif

.if ${PORT_OPTIONS:MPROFILER}
CONFIGURE_ARGS+=	--enable-profiler
.endif

regression-test: build
	@cd ${WRKSRC}; ${MAKE} check

post-build:
.if ${PORT_OPTIONS:MTEST}
	@cd ${WRKSRC}; ${MAKE} check
.endif

post-install:
.if ! ${PORT_OPTIONS:MDEBUG} && ! ${PORT_OPTIONS:MPROFILER}
	${STRIP_CMD} ${PREFIX}/bin/samefile
	${STRIP_CMD} ${PREFIX}/bin/samearchive
	${STRIP_CMD} ${PREFIX}/bin/samearchive-lite
	${STRIP_CMD} ${PREFIX}/bin/samecp
	${STRIP_CMD} ${PREFIX}/bin/samechflags
	${STRIP_CMD} ${PREFIX}/bin/samechmod
	${STRIP_CMD} ${PREFIX}/bin/samechown
	${STRIP_CMD} ${PREFIX}/bin/sameln
	${STRIP_CMD} ${PREFIX}/bin/samemv
	${STRIP_CMD} ${PREFIX}/bin/samerm
.if ${PORT_OPTIONS:MEXPERIMENTAL}
	${STRIP_CMD} ${PREFIX}/bin/fsort
.endif
.endif
.if ${PORT_OPTIONS:MDISK_STORAGE}
	${INSTALL_SCRIPT} ${FILESDIR}/samesame.sh ${PREFIX}/etc/rc.d/
.endif
	@${ECHO}
	@${CAT} pkg-message
	@${ECHO}

.include <bsd.port.mk>
