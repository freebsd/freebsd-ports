# New ports collection makefile for:	sysutils/p5-BSD-Sysctl
# Date created:		2006/09/05
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	BSD-Sysctl
PORTVERSION=	0.07
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	BSD
PKGNAMEPREFIX=	p5-

MAINTAINER=	david@landgren.net
COMMENT=	Fetch sysctl values from BSD-like systems

PERL_CONFIGURE=	yes

MAN3=		BSD::Sysctl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500600
IGNORE=	requires perl 5.6.0 or higher. Please install lang/perl5.8 and try again
.endif

.include <bsd.port.post.mk>
