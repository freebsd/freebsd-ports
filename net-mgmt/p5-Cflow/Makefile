# New ports collection makefile for:	p5-Cflow
# Date created:			Di  13 Mär 2001 19:37:25 CET
# Whom:				Andreas Klemm <andreas@klemm.gtn.com>
#
# $FreeBSD$
#

PORTNAME=	Cflow
PORTVERSION=	1.051
CATEGORIES=	net-mgmt perl5
MASTER_SITES=	http://net.doit.wisc.edu/~plonka/Cflow/
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Analyze raw flow files written by cflowd (Cisco NetFlow data)

.if exists(/usr/local/include/ftlib.h) && exists(/usr/local/lib/libft.a)
CFLAGS+=	-I${PREFIX}/include -DOSU
CONFIGURE_ARGS+=	\
	"LDDLFLAGS= -Wl,-E -shared -lperl -lm -L${PREFIX}/lib -lft -lz" \
	"INC= -I${PREFIX}/include" "LDLOADLIBS= -L${PREFIX}/lib -lft -lz"
.endif
PERL_CONFIGURE=	YES

MAN1=		flowdumper.1
MAN3=		Cflow.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
