# Created by: Andreas Klemm <andreas@klemm.gtn.com>
# $FreeBSD$

PORTNAME=	Cflow
PORTVERSION=	1.053
PORTREVISION=	2
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

FLOW_TOOLS_BUILD_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools
FLOW_TOOLS_RUN_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools
FLOW_TOOLS_NG_BUILD_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools-ng
FLOW_TOOLS_NG_RUN_DEPENDS=	${LOCALBASE}/lib/libft.a:net-mgmt/flow-tools-ng

post-patch:
	@${REINPLACE_CMD} -e 's|\.\./\.\./lib|${LOCALBASE}/lib|g' ${WRKSRC}/Makefile.PL

.include <bsd.port.mk>
