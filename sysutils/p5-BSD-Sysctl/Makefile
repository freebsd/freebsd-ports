# New ports collection makefile for:	sysutils/p5-BSD-Sysctl
# Date created:		2006/09/05
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	BSD-Sysctl
PORTVERSION=	0.08
CATEGORIES=	sysutils perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	david@landgren.net
COMMENT=	Fetch sysctl values from BSD-like systems

PERL_CONFIGURE=	yes

MAN3=		BSD::Sysctl.3

.include <bsd.port.pre.mk>

.if ${OSVERSION} >= 800070
BROKEN=		does not build
.endif

.include <bsd.port.post.mk>
