# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Sledge-Plugin-NoCache
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2363
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that outputs HTTP no-cache headers

DEPRECATED=	depends on mod_perl 1 which is gone
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::NoCache.3

.include <bsd.port.mk>
