# New ports collection makefile for: pandoc
# Date created:                      9 February 2007
# Whom:                              John MacFarlane <jgm@berkeley.edu>
#
# $FreeBSD$
#

PORTNAME=	pandoc
PORTVERSION=	1.4
CATEGORIES=	textproc haskell
MASTER_SITES=	${MASTER_SITE_GOOGLE_CODE}

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	A general markup converter

BUILD_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-zip-archive-ghc>=0.1.1.4:${PORTSDIR}/archivers/hs-zip-archive-ghc
RUN_DEPENDS=	ghc>=6.8:${PORTSDIR}/lang/ghc \
		hs-utf8-string-ghc>=0.3:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-zip-archive-ghc>=0.1:${PORTSDIR}/archivers/hs-zip-archive-ghc
LIB_DEPENDS=	gmp.8:${PORTSDIR}/math/libgmp4

MAN1=		pandoc.1 markdown2pdf.1 html2markdown.1 hsmarkdown.1

GHC_VERSION=		6.10.4
PANDOC_VERSION=	${PORTVERSION}
HLKATE_VERSION=		0.2.5.1

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
PANDOC_LIBDIR_REL=	lib/${DISTNAME}
DATADIR=		${PREFIX}/share/${DISTNAME}
PORTDATA=		*

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		PANDOC_VERSION=${PANDOC_VERSION} \
		PANDOC_LIBDIR_REL=${PANDOC_LIBDIR_REL}

OPTIONS=	HIGHLIGHTING "Syntax highlighting support" off

.include <bsd.port.pre.mk>

CONFIGURE_ARGS=	--haddock-options=-w --prefix=${PREFIX}
.if defined(NOPORTDATA)
CONFIGURE_ARGS+=	--datadir='' --datasubdir='' --docdir='${DOCSDIR}'
.endif

.if exists(${LOCALBASE}/lib/highlighting-kate-${HLKATE_VERSION}/register.sh)
WITH_HIGHLIGHTING=
.endif

.if defined(WITH_HIGHLIGHTING)
CONFIGURE_ARGS+=	--flags="highlighting"
BUILD_DEPENDS+=	hs-highlighting-kate-ghc>=0.2.3:${PORTSDIR}/textproc/hs-highlighting-kate-ghc
RUN_DEPENDS+=	hs-highlighting-kate-ghc>=0.2.3:${PORTSDIR}/textproc/hs-highlighting-kate-ghc
LIB_DEPENDS+=	pcre:${PORTSDIR}/devel/pcre
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=		NOPORTDOCS=""
.else
PLIST_SUB+=		NOPORTDOCS="@comment "
.endif

.if !defined(NOPORTDOCS)

PORT_HADDOCK!=	(cd  ${.CURDIR}/../../lang/ghc && ${MAKE} -V PORT_HADDOCK)
.if !empty(PORT_HADDOCK:M?0)
BUILD_DEPENDS+=	haddock:${PORTSDIR}/devel/hs-haddock
.endif
BUILD_DEPENDS+=	HsColour:${PORTSDIR}/print/hs-hscolour

HSCOLOUR_VERSION=	1.15
HSCOLOUR_DATADIR=	${PREFIX}/share/hscolour-${HSCOLOUR_VERSION}

PORTDOCS=	*
.endif

.SILENT:

do-configure:
	cd ${WRKSRC} && ${GHC_CMD} --make Setup.hs -o setup -package Cabal \
		     && ${SETUP_CMD} configure ${CONFIGURE_ARGS}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --executables --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${PANDOC_LIBDIR_REL}/register.sh
.for man in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${man} ${PREFIX}/man/man1
.endfor

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.post.mk>
