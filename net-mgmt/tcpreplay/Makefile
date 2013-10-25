# Created by: cnh@ivmg.net
# $FreeBSD$

PORTNAME=	tcpreplay
PORTVERSION=	3.4.4
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

BUILD_DEPENDS=	pcapnav-config:${PORTSDIR}/net/libpcapnav

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config \
		--enable-tcpreplay-edit

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}

.include <bsd.port.mk>
