# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
DISTVERSION=	2.0.7
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/
PKGNAMESUFFIX=	2

MAINTAINER=	olivier@FreeBSD.org
COMMENT=	Dynamic IP routing daemon

LICENSE=	GPLv2

USES=		bison gmake ncurses readline

CONFLICTS=	bird-[0-9]*
CONFLICTS+=	bird6-[0-9]*

USE_CSTD=	gnu99
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_RC_SUBR=	bird
SUB_FILES=	pkg-message

GROUPS=		birdvty

MAKE_JOBS_UNSAFE=	yes

OPTIONS_MULTI=	RP
RP_DESC=	Routing Protocols
OPTIONS_MULTI_RP=	BFD BABEL BGP MRT OSPF PIPE RADV RIP RPKI STATIC
OPTIONS_DEFAULT=	${OPTIONS_MULTI_RP}

BFD_DESC=	Bidirectional Forwarding Detection
BABEL_DESC=	Babel routing protocol
BGP_DESC=	Border Gateway Protocol
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
MRT_VARS=	rt_prot+=mrt
OSPF_VARS=	rt_prot+=ospf
PIPE_VARS=	rt_prot+=pipe
RADV_VARS=	rt_prot+=radv
RIP_VARS=	rt_prot+=rip
RPKI_VARS=	rt_prot+=rpki
STATIC_VARS=	rt_prot+=static

CONFIGURE_ARGS+=--with-protocols="${RT_PROT}"
RPKI_LIB_DEPENDS=	libssh.so:security/libssh

post-patch:
	#${REINPLACE_CMD} -e 's|\.example|\.sample|g' ${WRKSRC}/Makefile.in
	#${MV} ${WRKSRC}/doc/bird.conf ${WRKSRC}/doc/bird.conf.sample

.include <bsd.port.mk>
