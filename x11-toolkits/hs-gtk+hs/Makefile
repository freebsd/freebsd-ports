# New ports collection makefile for:   gtk+hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk+hs
PORTVERSION=	0.15.2
PORTREVISION=	1
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/gtk/
PKGNAMEPREFIX=	hs-

MAINTAINER=	obraun@FreeBSD.org
COMMENT=	A GTK+ Binding for Haskell

BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5 \
		c2hs:${PORTSDIR}/devel/hs-c2hs
RUN_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5 \
		c2hs:${PORTSDIR}/devel/hs-c2hs
.if !defined(WITHOUT_IHASKELL)
RUN_DEPENDS+=	ports-config:${PORTSDIR}/devel/hs-hpl
.endif

USE_SIZE=	yes
USE_GNOME=	glib12 gtk12
USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package
.if !defined(WITHOUT_IHASKELL)
CONFIGURE_ARGS+=	--with-ih
.endif

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	PORTVERSION="${PORTVERSION}" GHC_VERSION="${GHC_VERSION}"

pre-everything::
.if !defined(WITHOUT_IHASKELL)
	@${ECHO_CMD} "To build gtk+hs without iHaskell define WITHOUT_IHASKELL."
.endif

post-patch:
	@${REINPLACE_CMD} -e 's/gtk-config/gtk12-config/g ; \
			s/glib-config/glib12-config/g' ${WRKSRC}/configure
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
