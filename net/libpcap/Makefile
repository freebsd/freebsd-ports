# Created by: Bruce M Simpson <bms@FreeBSD.org>
# $FreeBSD$

PORTNAME=	libpcap
PORTVERSION=	1.5.2
CATEGORIES=	net ipv6
MASTER_SITES=	http://www.tcpdump.org/release/

MAINTAINER=	wxs@FreeBSD.org
COMMENT=	Ubiquitous network traffic capture library

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USES=		bison
USE_LDCONFIG=	yes

.if defined(LIBPCAP_OVERWRITE_BASE)
PREFIX=		/usr
PKGNAMESUFFIX=	-overwrite-base
MANPREFIX=	${PREFIX}/share
PKGMESSAGE=	${FILESDIR}/pkg-message-base
.endif


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
		include/pcap/bluetooth.h \
		include/pcap/bpf.h \
		include/pcap/ipnet.h \
		include/pcap/namedb.h \
		include/pcap/pcap.h \
		include/pcap/sll.h \
		include/pcap/usb.h \
		include/pcap/vlan.h \
		include/pcap.h \
		include/pcap-namedb.h \
		include/pcap-bpf.h \
		lib/libpcap.a \
		lib/libpcap.so.1 \
		lib/libpcap.so.${PORTVERSION} \
		lib/libpcap.so \
		man/man1/pcap-config.1.gz \
		man/man3/pcap.3.gz \
		man/man3/pcap_activate.3.gz \
		man/man3/pcap_breakloop.3.gz \
		man/man3/pcap_can_set_rfmon.3.gz \
		man/man3/pcap_close.3.gz \
		man/man3/pcap_compile.3.gz \
		man/man3/pcap_create.3.gz \
		man/man3/pcap_datalink.3.gz \
		man/man3/pcap_datalink_name_to_val.3.gz \
		man/man3/pcap_datalink_val_to_name.3.gz \
		man/man3/pcap_dump.3.gz \
		man/man3/pcap_dump_close.3.gz \
		man/man3/pcap_dump_file.3.gz \
		man/man3/pcap_dump_flush.3.gz \
		man/man3/pcap_dump_ftell.3.gz \
		man/man3/pcap_dump_open.3.gz \
		man/man3/pcap_file.3.gz \
		man/man3/pcap_fileno.3.gz \
		man/man3/pcap_findalldevs.3.gz \
		man/man3/pcap_freecode.3.gz \
		man/man3/pcap_get_tstamp_precision.3.gz \
		man/man3/pcap_get_selectable_fd.3.gz \
		man/man3/pcap_geterr.3.gz \
		man/man3/pcap_inject.3.gz \
		man/man3/pcap_is_swapped.3.gz \
		man/man3/pcap_lib_version.3.gz \
		man/man3/pcap_list_datalinks.3.gz \
		man/man3/pcap_list_tstamp_types.3.gz \
		man/man3/pcap_lookupdev.3.gz \
		man/man3/pcap_lookupnet.3.gz \
		man/man3/pcap_loop.3.gz \
		man/man3/pcap_major_version.3.gz \
		man/man3/pcap_next_ex.3.gz \
		man/man3/pcap_offline_filter.3.gz \
		man/man3/pcap_open_dead.3.gz \
		man/man3/pcap_open_live.3.gz \
		man/man3/pcap_open_offline.3.gz \
		man/man3/pcap_set_buffer_size.3.gz \
		man/man3/pcap_set_datalink.3.gz \
		man/man3/pcap_set_immediate_mode.3.gz \
		man/man3/pcap_set_promisc.3.gz \
		man/man3/pcap_set_rfmon.3.gz \
		man/man3/pcap_set_snaplen.3.gz \
		man/man3/pcap_set_timeout.3.gz \
		man/man3/pcap_set_tstamp_precision.3.gz \
		man/man3/pcap_set_tstamp_type.3.gz \
		man/man3/pcap_setdirection.3.gz \
		man/man3/pcap_setfilter.3.gz \
		man/man3/pcap_setnonblock.3.gz \
		man/man3/pcap_snapshot.3.gz \
		man/man3/pcap_stats.3.gz \
		man/man3/pcap_statustostr.3.gz \
		man/man3/pcap_strerror.3.gz \
		man/man3/pcap_tstamp_type_name_to_val.3.gz \
		man/man3/pcap_tstamp_type_val_to_name.3.gz \
		man/man5/pcap-savefile.5.gz \
		man/man7/pcap-filter.7.gz \
		man/man7/pcap-linktype.7.gz \
		man/man7/pcap-tstamp.7.gz
PLIST_DIRS+=	include/pcap

OPTIONS_DEFINE=	DAG IPV6

DAG_DESC=	Support for Endace DAG hardware

OPTIONS_DEFAULT=	IPV6

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MIPV6}
CONFIGURE_ARGS+=	--enable-ipv6
.endif

.if ${PORT_OPTIONS:MDAG}
LDFLAGS+=	-L${LOCALBASE}/lib
.else
CONFIGURE_ARGS+=	--without-dag
.endif

# Maybe make this into an OPTION?
.if defined(LIBPCAP_OVERWRITE_BASE)
post-install:
	${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.pre.mk>

# Packages are built on a kernel that has cloning, but the resulting
# package will be run on a system that does not have cloning (7.x).
# Always use bpf device, but specify CFLAGS if we have cloning.
CONFIGURE_ARGS+=	--with-pcap=bpf
.if ${OSVERSION} > 800043
CFLAGS+=	-DHAVE_DEVICE_CLONING=1
.endif

.if ${ARCH} == "amd64" || ${ARCH} == "sparc64"
CFLAGS+=	-fPIC
.endif

.include <bsd.port.post.mk>
