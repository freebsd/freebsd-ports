# New ports collection makefile for:	tcpreplay
# Date created:				2 November 2000
# Whom:					cnh@ivmg.net
#
# $FreeBSD$
#

PORTNAME=	tcpreplay
PORTVERSION=	3.4.2
CATEGORIES=	net-mgmt
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	A tool to replay saved packet capture files

BUILD_DEPENDS=	${LOCALBASE}/lib/libpcap.a:${PORTSDIR}/net/libpcap

GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CONFIGURE_ARGS=	--with-libpcap=${LOCALBASE} \
		--without-pcapnav-config \
		--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--enable-tcpreplay-edit

MAN1=		tcpreplay.1 tcpprep.1 tcprewrite.1 tcpbridge.1 tcpreplay-edit.1
PLIST_FILES=	bin/tcpreplay bin/tcpprep bin/tcprewrite bin/tcpbridge \
		bin/tcpreplay-edit

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
