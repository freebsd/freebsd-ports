# New ports collection makefile for:   gtk+hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk+hs
PORTVERSION=	0.11.5
PORTREVISION=	1
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/gtk/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		c2hs:${PORTSDIR}/devel/hs-c2hs
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		c2hs:${PORTSDIR}/devel/hs-c2hs

USE_GNOMENG=	yes
USE_GNOME=	glib12 gtk12

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX}

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

post-patch:
	${REINPLACE_CMD} -e 's/gtk-config/gtk12-config/g ; \
			s/glib-config/glib12-config/g' ${WRKSRC}/configure

.include <bsd.port.mk>
