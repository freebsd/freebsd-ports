# Created by: Alex de Kruijff
# $FreeBSD$

PORTNAME=	samesame
PORTVERSION=	1.10
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	http://samesame.kruijff.org/ \
		LOCAL/dhn

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
TEST_TARGET=	check

OPTIONS_DEFINE=			DEBUG DISK_STORAGE LOW_MEMORY_PROFILE \
				EXPERIMENTAL PROFILER
OPTIONS_SUB=			yes
DISK_STORAGE_DESC=		Allows temporarily storage on disk
LOW_MEMORY_PROFILE_DESC=	Low memory profile reduces functionality
EXPERIMENTAL_DESC=		Enables experimental functionality
PROFILER_DESC=			Enables gprof support

DISK_STORAGE_CONFIGURE_ENABLE=	disk-storage
LOW_MEMORY_PROFILE_CONFIGURE_ON=	--enable-low-memory-profile --disable-read-onces
EXPERIMENTAL_CONFIGURE_ENABLE=	experimental fsort #checksums preread
PROFILER_CONFIGURE_ENABLE=	profiler
DEBUG_CONFIGURE_ENABLE=		debug

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDEBUG} || ${PORT_OPTIONS:MPROFILER}
INSTALL_TARGET=		install
.endif

post-install-DISK_STORAGE-on:
	${INSTALL_SCRIPT} ${FILESDIR}/samesame.sh \
		${STAGEDIR}${PREFIX}/etc/rc.d/

.include <bsd.port.mk>
