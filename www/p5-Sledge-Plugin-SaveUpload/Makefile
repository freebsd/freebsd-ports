# Created by: Akinori MUSHA aka knu <knu@idaemons.org>
# $FreeBSD$

PORTNAME=	Sledge-Plugin-SaveUpload
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2431
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that copes with cross-device link errors in uploading

DEPRECATED=	depends on mod_perl 1 which is gone
EXPIRATION_DATE=	2012-11-28

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::SaveUpload.3

.include <bsd.port.mk>
