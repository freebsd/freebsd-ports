# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	Cflow
PORTVERSION=	1.053
PORTREVISION=	1
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/Cflow/ \
		http://net.doit.wisc.edu/~plonka/Cflow/old/
PKGNAMEPREFIX=	p5-

MAINTAINER=	fw@moov.de
COMMENT=	Analyze raw flow files written by cflowd (Cisco NetFlow data)

OPTIONS_SINGLE=	FT
OPTIONS_SINGLE_FT=	FLOW_TOOLS FLOW_TOOLS_NG
OPTIONS_DEFAULT=	FLOW_TOOLS
FLOW_TOOLS_DESC=	Enable flow-tools support
FLOW_TOOLS_NG_DESC=	Enable flow-tools-ng support

USES=		perl5
USE_PERL5=	configure

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MFLOW_TOOLS}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libft.a:${PORTSDIR}/net-mgmt/flow-tools
RUN_DEPENDS+=	${LOCALBASE}/lib/libft.a:${PORTSDIR}/net-mgmt/flow-tools
.endif

.if ${PORT_OPTIONS:MFLOW_TOOLS_NG}
BUILD_DEPENDS+=	${LOCALBASE}/lib/libft.a:${PORTSDIR}/net-mgmt/flow-tools-ng
RUN_DEPENDS+=	${LOCALBASE}/lib/libft.a:${PORTSDIR}/net-mgmt/flow-tools-ng
.endif

.if ${PORT_OPTIONS:MFLOW_TOOLS}||${PORT_OPTIONS:MFLOW_TOOLS_NG}
CFLAGS+=	-I${LOCALBASE}/include -DOSU
CONFIGURE_ARGS+=	\
	"LDDLFLAGS= -shared -L${LOCALBASE}/lib -lft -lz" \
	"INC= -I${LOCALBASE}/include" "LDLOADLIBS= -L${LOCALBASE}/lib -lft -lz"
.endif

.include <bsd.port.mk>
