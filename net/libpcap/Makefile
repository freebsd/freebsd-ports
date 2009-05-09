# New ports collection makefile for:	libpcap
# Date created:		10 December 2003
# Whom:			Bruce M Simpson <bms@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	libpcap
PORTVERSION=	1.0.0
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/
DISTNAME=	${PORTNAME}-${PORTVERSION}

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library

WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTVERSION}

MAKE_JOBS_SAFE=	yes
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_BISON=	build
USE_LDCONFIG=	yes

.if defined(LIBPCAP_OVERWRITE_BASE)
PREFIX=		/usr
PKGNAMESUFFIX=	-overwrite-base
MANPREFIX=	${PREFIX}/share
PKGMESSAGE=	${FILESDIR}/pkg-message-base
.endif

MAN1=		pcap-config.1
MAN3=		pcap.3 \
		pcap_activate.3 \
		pcap_breakloop.3 \
		pcap_can_set_rfmon.3 \
		pcap_close.3 \
		pcap_compile.3 \
		pcap_create.3 \
		pcap_datalink.3 \
		pcap_datalink_name_to_val.3 \
		pcap_datalink_val_to_name.3 \
		pcap_dump.3 \
		pcap_dump_close.3 \
		pcap_dump_file.3 \
		pcap_dump_flush.3 \
		pcap_dump_ftell.3 \
		pcap_dump_open.3 \
		pcap_file.3 \
		pcap_fileno.3 \
		pcap_findalldevs.3 \
		pcap_free_datalinks.3 \
		pcap_freealldevs.3 \
		pcap_freecode.3 \
		pcap_get_selectable_fd.3 \
		pcap_geterr.3 \
		pcap_inject.3 \
		pcap_is_swapped.3 \
		pcap_lib_version.3 \
		pcap_list_datalinks.3 \
		pcap_lookupdev.3 \
		pcap_lookupnet.3 \
		pcap_loop.3 \
		pcap_major_version.3 \
		pcap_next_ex.3 \
		pcap_offline_filter.3 \
		pcap_open_dead.3 \
		pcap_open_live.3 \
		pcap_open_offline.3 \
		pcap_set_buffer_size.3 \
		pcap_set_datalink.3 \
		pcap_set_promisc.3 \
		pcap_set_rfmon.3 \
		pcap_set_snaplen.3 \
		pcap_set_timeout.3 \
		pcap_setdirection.3 \
		pcap_setfilter.3 \
		pcap_setnonblock.3 \
		pcap_snapshot.3 \
		pcap_stats.3 \
		pcap_statustostr.3 \
		pcap_strerror.3
MAN5=		pcap-savefile.5
MAN7=		pcap-filter.7 pcap-linktype.7

MLINKS=		pcap_datalink_val_to_name.3 \
		    pcap_datalink_val_to_description.3 \
		pcap_dump_open.3 pcap_dump_fopen.3 \
		pcap_geterr.3 pcap_perror.3 \
		pcap_inject.3 pcap_sendpacket.3 \
		pcap_loop.3 pcap_dispatch.3 \
		pcap_major_version.3 pcap_minor_version.3 \
		pcap_next_ex.3 pcap_next.3 \
		pcap_open_offline.3 pcap_fopen_offline.3 \
		pcap_setnonblock.3 pcap_getnonblock.3

PLIST_FILES+=	bin/pcap-config \
		include/pcap/bpf.h \
		include/pcap/namedb.h \
		include/pcap/pcap.h \
		include/pcap/sll.h \
		include/pcap/usb.h \
		include/pcap.h \
		include/pcap-namedb.h \
		include/pcap-bpf.h \
		lib/libpcap.a \
		lib/libpcap.so.3 \
		lib/libpcap.so
PLIST_DIRS+=	include/pcap

.if !defined(WITHOUT_IPV6)
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if !defined(WITH_DAG)
CONFIGURE_ARGS+=	--without-dag
.endif

.if defined(LIBPCAP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
