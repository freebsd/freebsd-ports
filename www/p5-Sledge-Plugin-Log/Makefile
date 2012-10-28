# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Sledge-Plugin-Log
PORTVERSION=	0.02
CATEGORIES=	www sysutils perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2362
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that adds Log::Dispatch::Config on

DEPRECATED=	depends on mod_perl 1 which is gone
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	p5-Log-Dispatch-Config>=0:${PORTSDIR}/devel/p5-Log-Dispatch-Config

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::Log.3

.include <bsd.port.mk>
