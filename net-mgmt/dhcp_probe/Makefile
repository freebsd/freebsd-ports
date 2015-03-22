# Created by: Kevin Hung <khung@nullaxiom.com>
# $FreeBSD$

PORTNAME=	dhcp_probe
PORTVERSION=	1.3.0
CATEGORIES=	net-mgmt
MASTER_SITES=	https://www.net.princeton.edu/software/dhcp_probe/

MAINTAINER=	khung@nullaxiom.com
COMMENT=	Attempts to discover DHCP and BootP servers on a network

LICENSE=	GPLv2 addl
LICENSE_COMB=	multi
LICENSE_NAME_addl=Additional legal notices for copyrighted code
LICENSE_FILE_addl=${WRKSRC}/COPYING
LICENSE_PERMS_addl=dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

LIB_DEPENDS=	libnet.so:${PORTSDIR}/net/libnet

USE_AUTOTOOLS=	aclocal automake
AUTOMAKE_ARGS=	-a
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-libnet-include=${LOCALBASE}/include/libnet11/ --with-libnet-lib=${LOCALBASE}/lib/libnet11/
MANPREFIX=	${PREFIX}

USE_RC_SUBR=	dhcp_probe

SUB_FILES=	pkg-message

# Put additional licenses in DOCS
PORTDOCS=	COPYING*

# Can't use INSTALL_PROGRAM macro as we need to patch Makefile.am and
# regenerate Makefile.in
post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/sbin/dhcp_probe
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${WRKSRC}/COPYING* ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
