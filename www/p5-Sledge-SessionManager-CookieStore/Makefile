# New ports collection makefile for:	p5-Sledge-SessionManager-CookieStore
# Date created:		27 February 2003
# Whom:			Akinori MUSHA aka knu <knu@idaemons.org>
#
# $FreeBSD$
#

PORTNAME=	Sledge-SessionManager-CookieStore
PORTVERSION=	0.01
CATEGORIES=	www perl5
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE_JP}
MASTER_SITE_SUBDIR=	sledge/2367
PKGNAMEPREFIX=	p5-

MAINTAINER=	dhn@FreeBSD.org
COMMENT=	A Sledge extension that stores session data to HTTP cookies

BUILD_DEPENDS=	${PM_DEPENDS}
RUN_DEPENDS=	${PM_DEPENDS}

PM_DEPENDS=	p5-Sledge>=0:${PORTSDIR}/www/p5-Sledge
PM_DEPENDS+=	p5-Crypt-Blowfish>=0:${PORTSDIR}/security/p5-Crypt-Blowfish
PM_DEPENDS+=	p5-Crypt-CBC>=0:${PORTSDIR}/security/p5-Crypt-CBC
PM_DEPENDS+=	p5-Storable>=0:${PORTSDIR}/devel/p5-Storable

PERL_CONFIGURE=	yes

MAN3=		Sledge::SessionManager::CookieStore.3

.include <bsd.port.mk>
