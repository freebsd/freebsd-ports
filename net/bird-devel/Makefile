# Created by: Alexander V. Chernikov <melifaro@FreeBSD.org>
# $FreeBSD$

PORTNAME=	bird
DISTVERSION=	2.0.1
CATEGORIES=	net
MASTER_SITES=	ftp://bird.network.cz/pub/bird/
PKGNAMESUFFIX=	-devel

MAINTAINER=	melifaro@ipfw.ru
COMMENT=	Dynamic IP routing daemon (devel version)

LICENSE=	GPLv2

LIB_DEPENDS=	libssh.so:security/libssh

CONFLICTS=	bird-[0-9]*
CONFLICTS+=	bird6-[0-9]*

USES=		bison gmake ncurses readline
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--localstatedir=/var
USE_CSTD=	gnu89
USE_RC_SUBR=	bird

MAKE_JOBS_UNSAFE=	yes

OPTIONS_MULTI=	RP
RP_DESC=	Routing Protocols
OPTIONS_MULTI_RP=	BFD BABEL BGP OSPF PIPE RADV RIP STATIC
OPTIONS_DEFAULT=	${OPTIONS_MULTI_RP}

BFD_DESC=	Bidirectional Forwarding Detection
BABEL_DESC=	Babel routing protocol
BGP_DESC=	Border Gateway Protocol
OSPF_DESC=	Open Short Path First
PIPE_DESC=	PIPE routing
RADV_DESC=	Router Advertisement
RIP_DESC=	Routing Information Protocol
STATIC_DESC=	Static routing

BFD_VARS=	rt_prot+=bfd
BABEL_VARS=	rt_prot+=babel
BGP_VARS=	rt_prot+=bgp
OSPF_VARS=	rt_prot+=ospf
PIPE_VARS=	rt_prot+=pipe
RADV_VARS=	rt_prot+=radv
RIP_VARS=	rt_prot+=rip
STATIC_VARS=	rt_prot+=static

CONFIGURE_ARGS+=--with-protocols="${RT_PROT}"

.include <bsd.port.mk>
