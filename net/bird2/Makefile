PORTNAME=	bird
DISTVERSION=	2.17.2
CATEGORIES=	net
MASTER_SITES=	https://bird.nic.cz/download/
PKGNAMESUFFIX=	2

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Dynamic IP routing daemon
WWW=		https://bird.nic.cz/

LICENSE=	GPLv2

FLAVORS=	netlink rtsock
rtsock_PKGNAMESUFFIX=	2-rtsock

USES=		bison cpe gmake ncurses readline

CONFLICTS=	bird3

CPE_VENDOR=	nic

USE_CSTD=	gnu99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	bird
SUB_FILES=	pkg-message

GROUPS=		birdvty

MAKE_JOBS_UNSAFE=	yes

OPTIONS_MULTI=	RP
RP_DESC=	Routing Protocols
OPTIONS_MULTI_RP=	BFD BABEL BMP BGP MRT OSPF PIPE RADV RIP RPKI STATIC
OPTIONS_DEFAULT=	BFD BABEL BGP MRT OSPF PIPE RADV RIP RPKI STATIC

BFD_DESC=	Bidirectional Forwarding Detection
BABEL_DESC=	Babel routing protocol
BGP_DESC=	Border Gateway Protocol
BMP_DESC=	BGP Monitoring Protocol
MRT_DESC=	Dumping Routing Information in MRT Format
OSPF_DESC=	Open Short Path First
PIPE_DESC=	PIPE routing
RADV_DESC=	Router Advertisement
RIP_DESC=	Routing Information Protocol
RPKI_DESC=	Resource Public Key Infrastructure
STATIC_DESC=	Static routing

BFD_VARS=	rt_prot+=bfd
BABEL_VARS=	rt_prot+=babel
BGP_VARS=	rt_prot+=bgp
BMP_VARS=	rt_prot+=bmp
MRT_VARS=	rt_prot+=mrt
OSPF_VARS=	rt_prot+=ospf
PIPE_VARS=	rt_prot+=pipe
RADV_VARS=	rt_prot+=radv
RIP_VARS=	rt_prot+=rip
RPKI_VARS=	rt_prot+=rpki
STATIC_VARS=	rt_prot+=static

CONFIGURE_ARGS+=--with-protocols="${RT_PROT}"
RPKI_LIB_DEPENDS=	libssh.so:security/libssh

.include <bsd.port.options.mk>

.if ${FLAVOR:U} != rtsock
CONFIGURE_ARGS+=--with-sysconfig=bsd-netlink
.endif

.if ${OPSYS} == FreeBSD && ${OSVERSION} < 1400000
FLAVORS=	rtsock netlink
netlink_PKGNAMESUFFIX=	2-netlink
rtsock_PKGNAMESUFFIX=	2
.endif

.if ${OPSYS} == FreeBSD && (${OSVERSION} >= 1500000 && ${OSVERSION} < 1500017)
EXTRA_PATCHES=	${PATCHDIR}/extra-patch-netlink-route
.endif

.include <bsd.port.mk>
