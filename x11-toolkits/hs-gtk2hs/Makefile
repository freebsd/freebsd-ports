# New ports collection makefile for:   gtk2hs
# Date created:        03 June 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk2hs
PORTVERSION=	0.9.7
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK2 Binding for Haskell

BUILD_DEPENDS=	ghc-6.2.2:${PORTSDIR}/lang/ghc \
		${X11BASE}/lib/mozilla/libxpcom.so:${PORTSDIR}/www/mozilla
RUN_DEPENDS=	${BUILD_DEPENDS}

BROKEN=		Broken dependency
DEPRECATED=	${BROKEN}
EXPIRATION_DATE=2005-09-22

USE_GNOME=	gtk20 libglade2 gtksourceview gconf2
GNU_CONFIGURE=	yes
USE_GMAKE=	yes

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC_VERSION="${GHC_VERSION}"

.include <bsd.port.mk>
