# New ports collection makefile for:	p5-Sledge-Plugin-Log
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge-Plugin-Log
PORTVERSION=	0.02
CATEGORIES=	www sysutils perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2362
PKGNAMEPREFIX=	p5-

MAINTAINER=	knu@FreeBSD.org
COMMENT=	A Sledge plug-in that adds Log::Dispatch::Config on

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	${SITE_PERL}/Sledge.pm:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	${SITE_PERL}/Log/Dispatch/Config.pm:${PORTSDIR}/devel/p5-Log-Dispatch-Config

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::Log.3
MAN3PREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.mk>
