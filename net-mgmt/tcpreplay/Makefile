# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	2.2.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	A tool to replay saved packet capture files

BUILD_DEPENDS=	${LOCALBASE}/lib/libnet.a:${PORTSDIR}/net/libnet-devel \
		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=	yes
# Pickup correct pcap.h; CFLAGS gets overwritten
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include"
CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE} \
		--without-pcapnav-config

MAN1=		capinfo.1 tcpprep.1 pcapmerge.1 flowreplay.1
MAN8=		tcpreplay.8

PLIST_FILES=	bin/capinfo bin/pcapmerge bin/tcpprep sbin/tcpreplay bin/flowreplay

.include <bsd.port.mk>
