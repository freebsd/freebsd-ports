# New ports collection makefile for:   gtk+hs
# Date created:        23 August 2002
# Whom:                Oliver Braun <obraun@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	gtk+hs
PORTVERSION=	0.15.3
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://www.cse.unsw.edu.au/~chak/haskell/gtk/
PKGNAMEPREFIX=	hs-

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GTK+ Binding for Haskell

OPTIONS=	GHC5 "Build for ghc5" off \
		IHASKELL "Build with iHaskell" off

BROKEN=		"Build fails"
EXPIRATION_DATE=2005-02-18
DEPRECATED=	${BROKEN}

USE_GNOME=	glib12 gtk12

.include <bsd.port.pre.mk>

.if defined(WITH_GHC5)
GHC=		ghc-5.04.3
GHCDEP=		ghc5
GHCMAJOR=	5
.else
GHC=		ghc-6.2.2
GHCDEP=		ghc
GHCMAJOR=	6
.endif
PKGNAMESUFFIX=	-${GHCDEP}

BUILD_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}
RUN_DEPENDS=	${GHC}:${PORTSDIR}/lang/${GHCDEP}

BUILD_DEPENDS+=	c2hs:${PORTSDIR}/devel/hs-c2hs
RUN_DEPENDS+=	c2hs:${PORTSDIR}/devel/hs-c2hs

.if defined(WITH_IHASKELL)
RUN_DEPENDS+=	ports-config:${PORTSDIR}/devel/hs-hpl
.endif

USE_REINPLACE=	yes
HAS_CONFIGURE=	yes
USE_GMAKE=	yes

CONFIGURE_ARGS+=	--prefix=${PREFIX} --enable-add-package
.if defined(WITH_IHASKELL)
CONFIGURE_ARGS+=	--with-ih
.endif

GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	PORTVERSION="${PORTVERSION}" GHC_VERSION="${GHC_VERSION}"
PLIST_SUB+=	GHCMAJOR="${GHCMAJOR}"

post-patch:
	@${REINPLACE_CMD} -e 's/gtk-config/gtk12-config/g ; \
			s/glib-config/glib12-config/g' ${WRKSRC}/configure
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
