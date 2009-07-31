# New ports collection makefile for:    Video-OpenQuicktime
# Date created:                         Sun Feb 22 23:06:26 EST 2004
# Whom:                                 Michael Johnson <ahze@ahze.net>
#
# $FreeBSD$
#

PORTNAME=	Video-OpenQuicktime
PORTVERSION=	1.02
PORTREVISION=	4
CATEGORIES=	multimedia perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interface to the OpenQuicktime library

BUILD_DEPENDS=	${SITE_PERL}/Inline-API.pod:${PORTSDIR}/devel/p5-Inline
LIB_DEPENDS=	openquicktime.0:${PORTSDIR}/multimedia/openquicktime
RUN_DEPENDS=	${SITE_PERL}/Inline-API.pod:${PORTSDIR}/devel/p5-Inline

PERL_CONFIGURE=	yes

MAN3=	Video::OpenQuicktime.3

.include <bsd.port.mk>
