# Created by: Kevin Hung <khung@nullaxiom.com>
# $FreeBSD$

PORTNAME=	dhcp_probe
PORTVERSION=	1.3.0
PORTREVISION=	1
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.net.princeton.edu/software/dhcp_probe/

MAINTAINER=	khung@nullaxiom.com
COMMENT=	Attempts to discover DHCP and BootP servers on a network

LICENSE=	GPLv2 LGPL20 addl
LICENSE_COMB=	multi
LICENSE_FILE_GPLv2=${WRKSRC}/COPYING.GPL
LICENSE_FILE_LGPL20=${WRKSRC}/COPYING.LIB
LICENSE_NAME_addl=Additional legal notices for copyrighted code
LICENSE_FILE_addl=${WRKSRC}/COPYING
LICENSE_PERMS_addl=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libnet.so:net/libnet

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip

USE_RC_SUBR=	dhcp_probe

SUB_FILES=	pkg-message

post-install:
	${INSTALL_DATA} ${WRKSRC}/extras/dhcp_probe.cf.sample \
		${STAGEDIR}${PREFIX}/etc

.include <bsd.port.mk>
