# New ports collection makefile for:	AnyEvent::MPRPC
# Date created:		20 Oct 2011
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	AnyEvent-MPRPC
PORTVERSION=	0.11
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension for simple TCP-based MPRPC client/server

RUN_DEPENDS=	\
	p5-Any-Moose>=0.13:${PORTSDIR}/devel/p5-Any-Moose \
	p5-AnyEvent>=5.261:${PORTSDIR}/devel/p5-AnyEvent \
	p5-Data-MessagePack>=0.34:${PORTSDIR}/devel/p5-Data-MessagePack
BUILD_DEPENDS=	${RUN_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=	AnyEvent::MPRPC.3 \
	AnyEvent::MPRPC::Client.3 \
	AnyEvent::MPRPC::CondVar.3 \
	AnyEvent::MPRPC::Server.3 \
	AnyEvent::MessagePack.3

.include <bsd.port.mk>
