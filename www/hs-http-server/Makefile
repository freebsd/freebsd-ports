# New ports collection makefile for: hs-http-server
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	http-server
PORTVERSION=	1
CATEGORIES=	www haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A library fro writing Haskell web servers

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-url>=2:${PORTSDIR}/www/hs-url \
		hs-HTTP>=4000.0.7:${PORTSDIR}/www/hs-HTTP \
		hs-utf8-string-ghc>=0.3.4:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-mime>=0.3:${PORTSDIR}/mail/hs-mime
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-url>=2:${PORTSDIR}/www/hs-url \
		hs-HTTP>=4000.0.7:${PORTSDIR}/www/hs-HTTP \
		hs-utf8-string-ghc>=0.3.4:${PORTSDIR}/devel/hs-utf8-string-ghc \
		hs-mime>=0.3:${PORTSDIR}/mail/hs-mime

GHC_VERSION=		6.10.4
HTTPSERVER_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

EXAMPLESDIR=	${PREFIX}/share/examples/${DISTNAME}
PORTEXAMPLES=	*

DOCSDIR=	${PREFIX}/share/doc/${DISTNAME}
HTTPSERVER_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		HTTPSERVER_VERSION=${HTTPSERVER_VERSION} \
		HTTPSERVER_LIBDIR_REL=${HTTPSERVER_LIBDIR_REL}

.if !defined(NOPORTEXAMPLES)
SUB_FILES=	pkg-message
.endif

.if defined(NOPORTDOCS)
PLIST_SUB+=	NOPORTDOCS=""
.else
PLIST_SUB+=	NOPORTDOCS="@comment "
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
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX}

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${HTTPSERVER_LIBDIR_REL}/register.sh
.if !defined(NOPORTEXAMPLES)
	${MKDIR} ${EXAMPLESDIR} && cd ${WRKSRC}/example && ${COPYTREE_SHARE} \* ${EXAMPLESDIR}
.endif

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old
.if !defined(NOPORTEXAMPLES)
	@${ECHO_MSG} -e "\a"
	@${ECHO_MSG} "================================================================="
	@${CAT}      "${PKGMESSAGE}"
	@${ECHO_MSG} "================================================================="
	@${ECHO_MSG}
.endif

.include <bsd.port.mk>
