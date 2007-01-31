# New ports collection makefile for:   tcpreplay
# Date created:        2 November 2000
# Whom:                cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	2.3.5
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	laszlof@FreeBSD.org
COMMENT=	A tool to replay saved packet capture files

BUILD_DEPENDS=	${LIBNET_CONFIG}:${PORTSDIR}/net/libnet \
		${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE} \
		--without-pcapnav-config
CFLAGS+=	`${LIBNET_CONFIG} --cflags` -I${LOCALBASE}/include

MAN1=		capinfo.1 tcpprep.1 pcapmerge.1 flowreplay.1
MAN8=		tcpreplay.8

PLIST_FILES=	bin/capinfo bin/pcapmerge bin/tcpprep sbin/tcpreplay bin/flowreplay

LIBNET_CONFIG?=	${LOCALBASE}/bin/libnet11-config

post-patch:
	@${REINPLACE_CMD} -Ee \
		's|-pipe -Wall|$$CFLAGS &|; \
		 s|^(foundnet=)no|\1yes|; \
		 s|\$$LNETLIB|`${LIBNET_CONFIG} --libs`|; \
		 s|\$$LNETINCDIR/||' \
		${CONFIGURE_WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
