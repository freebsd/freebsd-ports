# New ports collection makefile for:	p5-Net-Libdnet
# Date created:		21 August 2006
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Net-Libdnet
PORTVERSION=	0.01
CATEGORIES=	net perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Libdnet interface

LIB_DEPENDS=	dnet.1:${PORTSDIR}/net/libdnet

PERL_CONFIGURE=	5.8.0+
CONFIGURE_ARGS=	INC='-I${LOCALBASE}/include'
MAN3=		${PORTNAME:S/-/::/g}.3

.include <bsd.port.mk>
