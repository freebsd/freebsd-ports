# New ports collection makefile for:	p5-Sledge-Plugin-SaveUpload
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge-Plugin-SaveUpload
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2431
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge plug-in that copes with cross-device link errors in uploading

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	${SITE_PERL}/Sledge.pm:${PORTSDIR}/www/p5-Sledge

PERL_CONFIGURE=	yes

MAN3=		Sledge::Plugin::SaveUpload.3

.include <bsd.port.mk>
