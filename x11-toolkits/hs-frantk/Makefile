# New ports collection makefile for:   frantk
# Date created:        25 May 2002
# Whom:                Oliver Braun <obraun@informatik.unibw-muenchen.de>
#
# $FreeBSD$
#

PORTNAME=	frantk
PORTVERSION=	1.1
PORTREVISION=	3
CATEGORIES=	x11-toolkits haskell
MASTER_SITES=	http://www.dcs.gla.ac.uk/~meurig/FranTk/
PKGNAMEPREFIX=	hs-
DISTNAME=	FranTk${PORTVERSION:S/./_/}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A GUI library for Haskell on top of Tcl-Tk

LIB_DEPENDS=	tk84.1:${PORTSDIR}/x11-toolkits/tk84
.if !defined(WITHOUT_GHC)
BUILD_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5
RUN_DEPENDS=	ghc-5.04.3:${PORTSDIR}/lang/ghc5
.endif

USE_GMAKE=	yes
WRKSRC=		${WRKDIR}/FranTk1.1/src

.if defined(WITH_HUGS)
ALL_TARGET=	hugs
INSTALL_TARGET=	install_hugs
PLIST_SUB+=	HUGS=""
.else
PLIST_SUB+=	HUGS="@comment "
.endif

.if !defined(WITHOUT_GHC)
ALL_TARGET+=	all
INSTALL_TARGET+=install_ghc pkg
GHC_VERSION=	`${LOCALBASE}/bin/ghc --numeric-version`
PLIST_SUB+=	GHC="" GHC_VERSION="${GHC_VERSION}"
.else
PLIST_SUB+=	GHC="@comment "
.endif

pre-fetch:
	@${ECHO} ""
.if !defined(WITHOUT_GHC) && !defined(WITH_HUGS)
	@${ECHO} "   FranTk will be build and installed for ghc by default"
	@${ECHO} "   Define WITHOUT_GHC to build not for ghc"
	@${ECHO} "   Define WITH_HUGS   to build     for hugs"
	@${ECHO} ""
.endif
.if defined(WITHOUT_GHC) && !defined(WITH_HUGS)
	@${ECHO} "   You have defined WITHOUT_GHC and you have not defined WITH_HUGS"
	@${ECHO} "   This means FranTk will not be installed"
	@${ECHO} ""
	@${FALSE}
.elif !defined(WITHOUT_GHC)
	@${ECHO} "      Building for ghc"
.endif
.if defined(WITH_HUGS)
	@${ECHO} "      Building for hugs"
.endif
	@${ECHO} ""

post-patch:
	@${REINPLACE_CMD} "s|%%PREFIX%%|${PREFIX}|g" ${WRKSRC}/frantk.conf

post-install:
.if !defined(WITHOUT_GHC)
	@${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.endif
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${CP} ${WRKDIR}/FranTk1.1/doc/frantk.pdf ${DOCSDIR}
.endif
.if defined(WITH_HUGS)
	@${CAT} ${PKGMESSAGE}
.endif

.include <bsd.port.mk>
