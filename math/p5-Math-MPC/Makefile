# New ports collection makefile for:	Math-MPC
# Date created:				05 April, 2009
# Whom:					Wen Heping <wenheping@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	Math-MPC
PORTVERSION=	0.70
CATEGORIES=	math perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	wen@FreeBSD.org
COMMENT=	A perl interface to MPC Library

LIB_DEPENDS=	mpc.2:${PORTSDIR}/math/mpc

PERL_CONFIGURE=	yes
MAKE_ENV=	INC="-I${LOCALBASE}/include"

MAN3=		Math::MPC.3

.include <bsd.port.mk>
