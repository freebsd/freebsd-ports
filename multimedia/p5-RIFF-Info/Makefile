# New ports collection makefile for:    RIFF-Info
# Date created:                         Tue Feb 24 21:49:06 EST 2004
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	RIFF-Info
PORTVERSION=	1.07
CATEGORIES=	multimedia perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	Video/ALLENDAY
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Probe DivX and AVI files for attributes

BUILD_DEPENDS=	${SITE_PERL}/Video/Info/RIFF.pm:${PORTSDIR}/multimedia/p5-Video-Info
RUN_DEPENDS=	${SITE_PERL}/Video/Info/RIFF.pm:${PORTSDIR}/multimedia/p5-Video-Info

PERL_CONFIGURE=	YES

MAN3=	RIFF::Info.3 \
	RIFF::Info::DivX.3 \
	RIFF::Info::AVI.3

.include <bsd.port.mk>
