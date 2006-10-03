# New ports collection makefile for:	sysutils/p5-BSD-Sysctl
# Date created:		2006/09/05
# Whom:			chinsan <chinsan.tw@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	BSD-Sysctl
PORTVERSION=	0.03
CATEGORIES=	sysutils perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DL/DLAND
PKGNAMEPREFIX=	p5-

MAINTAINER=	chinsan@FreeBSD.org
COMMENT=	Fetch sysctl values from BSD-like systems

NOT_FOR_ARCHS=	amd64
NOT_FOR_ARCHS_REASON_amd64=	lack of machine/bootinfo.h to compile

PERL_CONFIGURE=	yes

MAN3=		BSD::Sysctl.3

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500806
IGNORE=		requires perl 5.8.6 or later. Install lang/perl5.8 then try again
.endif

.include <bsd.port.post.mk>
