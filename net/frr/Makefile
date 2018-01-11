# $FreeBSD$

PORTNAME=	frr
PORTVERSION=	3.0.2
DISTVERSIONPREFIX=	frr-
PORTREVISION=	1
CATEGORIES=	net ipv6

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	IP routing protocol suite including BGP, IS-IS, OSPF and RIP

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	gawk:lang/gawk
LIB_DEPENDS=	libjson-c.so:devel/json-c

CONFLICTS=	openbgpd openospfd zebra quagga-esr quagga

USE_GITHUB=	yes
GH_ACCOUNT=	FRRouting

GNU_CONFIGURE=	yes
INSTALL_TARGET=	install-strip
USES=		autoreconf bison gmake pkgconfig libtool makeinfo readline
USE_LDCONFIG=	yes

INFO=		frr

OPTIONS_DEFINE=		FPM LDPD PAM SHELLACCESS TCPSOCKETS VTYSH MULTIPATH TCMALLOC
OPTIONS_DEFAULT=	VTYSH
OPTIONS_SUB=	yes
# SNMP option build failed
# checksum.c:79:21: warning: implicit declaration of function 'typeof' is
#   invalid in C99 [-Wimplicit-function-declaration]
# IRDP option needs something freebsd does not seem to have:
# configure: error: 'IRDP requires in_pktinfo at the moment!'

FPM_DESC=		Enable Forwarding Plane Manager support
LDPD_DESC=		Build ldpd
MULTIPATH_DESC=		Enable multipath function
PAM_DESC=		Use libpam for PAM support in vtysh
SHELLACCESS_DESC=	Allow users to access shell/telnet/ssh
SNMP_DESC=		SNMP support
TCMALLOC_DESC=		Use tcmalloc
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
VTYSH_DESC=		Build integrated vty shell

USERS=	frr
GROUPS=	frr frrvty

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
INSTALL_TARGET=	install-strip

# PIM compile but didn't work on FreeBSD
CONFIGURE_ARGS=	--enable-user=frr \
		--enable-group=frr \
		--enable-vty-group=frrvty \
		--sysconfdir=${ETCDIR} \
		--localstatedir=/var/run/frr \
		--disable-pimd

SHELLACCESS_CONFIGURE_ENABLE=	shell-access
FPM_CONFIGURE_ENABLE=		fpm
PAM_CONFIGURE_WITH=		libpam
LDPD_CONFIGURE_ENABLE=		ldpd
MULTIPATH_CONFIGURE_ON=		--enable-multipath=64
TCMALLOC_CONFIGURE_ENABLE=	tcmalloc
TCMALLOC_LIB_DEPENDS=		libtcmalloc.so:devel/google-perftools
SNMP_CONFIGURE_ENABLE=		snmp
SNMP_LIB_DEPENDS=		libnetsnmp.so:net-mgmt/net-snmp
TCPSOCKETS_CONFIGURE_ENABLE=	tcp-zebra
VTYSH_CONFIGURE_ENABLE=		vtysh

USE_RC_SUBR=	frr watchfrr

post-install:
	${MKDIR} ${STAGEDIR}/var/run/frr

.include <bsd.port.mk>
