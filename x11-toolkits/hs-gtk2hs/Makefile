# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.9.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK2 Binding for Haskell

BUILD_DEPENDS=	ghc-6.2.2:${PORTSDIR}/lang/ghc
RUN_DEPENDS=	ghc-6.2.2:${PORTSDIR}/lang/ghc

USE_GNOME=	gtk20 libglade gtksourceview
HAS_CONFIGURE=	yes
CONFIGURE_ARGS+=	--with-c2hs=no
USE_GMAKE=	yes
MAKE_ENV+=	BUILDDOCS=no

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

.include <bsd.port.mk>
