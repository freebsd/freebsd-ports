# New ports collection makefile for:	p5-Cflow
# Date created:			Di  13 Mär 2001 19:37:25 CET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Cflow
PORTVERSION=	1.051
PORTREVISION=	2
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/Cflow/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyze raw flow files written by cflowd (Cisco NetFlow data)

.if defined(WITH_FLOW_TOOLS)
RUN_DEPENDS+=	${LOCALBASE}/lib/libft.a:${PORTSDIR}/net-mgmt/flow-tools

CFLAGS+=	-I${LOCALBASE}/include -DOSU
CONFIGURE_ARGS+=	\
	"LDDLFLAGS= -shared -L${LOCALBASE}/lib -lft -lz" \
	"INC= -I${LOCALBASE}/include" "LDLOADLIBS= -L${LOCALBASE}/lib -lft -lz"
.endif
PERL_CONFIGURE=	YES

MAN1=		flowdumper.1
MAN3=		Cflow.3

.include <bsd.port.mk>
