# Created by: cnh@ivmg.net
# $FreeBSD$

PORTNAME=	tcpreplay
PORTVERSION=	4.0.3
CATEGORIES=	net-mgmt
MASTER_SITES=	SF

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Tool to replay saved packet capture files

LICENSE=	GPLv3

BUILD_DEPENDS=	pcapnav-config:${PORTSDIR}/net/libpcapnav

GNU_CONFIGURE=	yes

CONFIGURE_ARGS=	--program-transform-name='s|.*\(tcp.*\)|\1|' \
		--with-pcapnav-config=${LOCALBASE}/bin/pcapnav-config

# does not build on FreeBSD 8.x
PORTSCOUT=	skipv:4.0.4

post-patch:
	@${REINPLACE_CMD} -e 's|-Wall -O3||' ${WRKSRC}/${CONFIGURE_SCRIPT}

regression-test: build
	@cd ${WRKSRC} && ${MAKE} -s test

.include <bsd.port.mk>
