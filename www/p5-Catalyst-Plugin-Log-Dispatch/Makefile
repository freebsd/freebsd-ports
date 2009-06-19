# New ports collection makefile for:	p5-Catalyst-Plugin-Log-Dispatch
# Date created:				2008-07-02
# Whom:					Oleg Mamontov <oleg@mamontov.net>
#
# $FreeBSD$
#

PORTNAME=	Catalyst-Plugin-Log-Dispatch
PORTVERSION=	0.11
CATEGORIES=	www perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	oleg@mamontov.net
COMMENT=	Log module of Catalyst that uses Log::Dispatch

BUILD_DEPENDS=	p5-Log-Dispatch>=2.13:${PORTSDIR}/devel/p5-Log-Dispatch		\
		p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config	\
		p5-Catalyst-Runtime>=5.65:${PORTSDIR}/www/p5-Catalyst-Runtime	\
		p5-UNIVERSAL-require>=0:${PORTSDIR}/devel/p5-UNIVERSAL-require
RUN_DEPENDS=	${BUILD_DEPENDS}

PERL_CONFIGURE=	yes

MAN3=		Catalyst::Plugin::Log::Dispatch.3

.include <bsd.port.mk>
