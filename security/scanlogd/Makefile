# Created by: Roman Bogorodskiy
# $FreeBSD$

PORTNAME=	scanlogd
PORTVERSION=	2.2.8
CATEGORIES=	security
MASTER_SITES=	http://openwall.com/scanlogd/ \
		ftp://ftp.openwall.com/pub/projects/scanlogd/ \
		ftp://rt.fm/pub/scanlogd/

MAINTAINER=	novel@FreeBSD.org
COMMENT=	TCP port scan detection tool

USE_RC_SUBR=	${PORTNAME}

USERS=		scanlogd
GROUPS=		scanlogd
MAKE_ARGS=	CC="${CC}" CFLAGS="${CFLAGS}" LD="${CC}" LDFLAGS="${LDFLAGS}"

PLIST_FILES=	bin/scanlogd man/man8/scanlogd.8.gz \
		etc/periodic/security/850.scanlogd

OPTIONS_SINGLE=	PCAP
OPTIONS_SINGLE_PCAP=	PCAP_BASE NIDS

OPTIONS_DEFAULT=	PCAP_BASE

PCAP_BASE_DESC=	Use pcap from base for packet capture
NIDS_DESC=	Use net/libnet for packet capture

PCAP_BASE_ALL_TARGET=	libpcap

NIDS_ALL_TARGET=	libnids
NIDS_BUILD_DEPENDS=	${LOCALBASE}/lib/libnids.a:net/libnids
NIDS_LIB_DEPENDS=	libnet.so:net/libnet

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/scanlogd ${STAGEDIR}${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/scanlogd.8 ${STAGEDIR}${MANPREFIX}/man/man8
	${MKDIR} ${STAGEDIR}${PREFIX}/etc/periodic/security
	${INSTALL_SCRIPT} ${FILESDIR}/850.scanlogd \
		${STAGEDIR}${PREFIX}/etc/periodic/security

.include <bsd.port.mk>
