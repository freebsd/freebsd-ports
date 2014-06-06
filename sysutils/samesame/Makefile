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

LICENSE=	BSD2CLAUSE

CONFLICTS=	samefile-[0-9]*

HAS_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
CONFIGURE_ARGS=	--enable-samechflags --enable-samechmod \
		--mandir="${MANPREFIX}/man" --prefix="${PREFIX}" \
		--includedir="${LOCALBASE}/include" --libdir="${LOCALBASE}/lib"
USES=		tar:bzip2

OPTIONS_DEFINE=			DEBUG DISK_STORAGE LOW_MEMORY_PROFILE \
				EXPERIMENTAL PROFILER TEST
OPTIONS_SUB=			yes
DISK_STORAGE_DESC=		Allows temporarily storage on disk
LOW_MEMORY_PROFILE_DESC=	Low memory profile reduces functionality
EXPERIMENTAL_DESC=		Enables experimental functionality
PROFILER_DESC=			Enables gprof support
TEST_DESC=			Run quality assurance test

DISK_STORAGE_CONFIGURE_ENABLE=	disk-storage
EXPERIMENTAL_CONFIGURE_ENABLE=	experimental fsort #checksums preread
PROFILE_CONFIGURE_ENABLE=	profiler
DEBUG_CONFIGURE_ENABLE=		debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG} || ${PORT_OPTIONS:MPROFILER}
INSTALL_TARGET=		install
.endif

.if ${PORT_OPTIONS:MLOW_MEMORY_PROFILE}
CONFIGURE_ARGS+=	--enable-low-memory-profile --disable-read-onces
.endif

regression-test: build
	@cd ${WRKSRC}; ${MAKE} check

post-build:
.if ${PORT_OPTIONS:MTEST}
	@cd ${WRKSRC}; ${MAKE} check
.endif

post-install:
.if ${PORT_OPTIONS:MDISK_STORAGE}
	${INSTALL_SCRIPT} ${FILESDIR}/samesame.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/
.endif

.include <bsd.port.mk>
