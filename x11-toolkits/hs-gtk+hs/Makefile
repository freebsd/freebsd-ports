# New ports collection makefile for:   gtk+hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk+hs
PORTVERSION=	0.14.10
PORTCOMMENT=	A GTK+ Binding for Haskell
CATEGORIES=	x11-toolkits
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/gtk/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org

BUILD_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		c2hs:${PORTSDIR}/devel/hs-c2hs
RUN_DEPENDS=	ghc:${PORTSDIR}/lang/ghc \
		c2hs:${PORTSDIR}/devel/hs-c2hs
.if defined(WITH_IHASKELL)
RUN_DEPENDS+=	ports-config:${PORTSDIR}/devel/hs-hpl
.endif

USE_GNOMENG=	yes
USE_GNOME=	glib12 gtk12

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package
.if defined(WITH_IHASKELL)
CONFIGURE_ARGS+=	--with-ih
.endif

PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

pre-everything::
.if !defined(WITH_IHASKELL)
	@${ECHO_CMD} "To build gtk+hs with iHaskell define WITH_IHASKELL."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/gtk-config/gtk12-config/g ; \
			s/glib-config/glib12-config/g' ${WRKSRC}/configure

.include <bsd.port.mk>
