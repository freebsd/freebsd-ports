# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Sledge-Plugin-Download
PORTVERSION=	0.02
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2360
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that works around browser bugs with file downloading

DEPRECATED=	depends on mod_perl 1 which is gone
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::Download.3

.include <bsd.port.mk>
