# New ports collection makefile for: hs-fastcgi
# Date created:        December 20 2009
# Whom:                Giuseppe Pilichi aka Jacula Modyun <jacula@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	fastcgi
PORTVERSION=	3001.0.2.2
CATEGORIES=	www haskell
MASTER_SITES=	http://hackage.haskell.org/packages/archive/${PORTNAME}/${PORTVERSION}/
PKGNAMEPREFIX=	hs-

MAINTAINER=	jacula@gmail.com
COMMENT=	A Haskell library for writing FastCGI programs

BUILD_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-cgi>=3000.0.0:${PORTSDIR}/www/hs-cgi
RUN_DEPENDS+=	ghc:${PORTSDIR}/lang/ghc \
		hs-cgi>=3000.0.0:${PORTSDIR}/www/hs-cgi
LIB_DEPENDS=	fcgi.0:${PORTSDIR}/www/fcgi

GHC_VERSION=		6.10.4
FASTCGI_VERSION=	${PORTVERSION}

GHC_CMD=	${LOCALBASE}/bin/ghc
SETUP_CMD=	./setup

LDFLAGS+=	-L${LOCALBASE}/lib
CPPFLAGS+=	-I${LOCALBASE}/include

DOCSDIR=		${PREFIX}/share/doc/${DISTNAME}
FASTCGI_LIBDIR_REL=	lib/${DISTNAME}

PLIST_SUB=	GHC_VERSION=${GHC_VERSION} \
		FASTCGI_VERSION=${FASTCGI_VERSION} \
		FASTCGI_LIBDIR_REL=${FASTCGI_LIBDIR_REL}

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
	cd ${WRKSRC} && ${SETENV} LDFLAGS="${LDFLAGS}" CPPFLAGS=" ${CPPFLAGS}" ./${CONFIGURE_SCRIPT} \
		     && ${GHC_CMD} --make Setup.lhs -o setup -package Cabal \
		     && ${SETUP_CMD} configure --haddock-options=-w --prefix=${PREFIX} \
		     				--extra-include-dirs=${LOCALBASE}/include \
						--extra-lib-dirs=${LOCALBASE}/lib

do-build:
	cd ${WRKSRC} && ${SETUP_CMD} build \
		     && ${SETUP_CMD} register --gen-script

.if !defined(NOPORTDOCS)
	cd ${WRKSRC} && ${SETUP_CMD} haddock --hyperlink-source \
					     --hscolour-css=${HSCOLOUR_DATADIR}/hscolour.css
.endif

do-install:
	cd ${WRKSRC} && ${SETUP_CMD} install \
		     && ${INSTALL_SCRIPT} register.sh ${PREFIX}/${FASTCGI_LIBDIR_REL}/register.sh

post-install:
	${RM} -f ${PREFIX}/lib/ghc-${GHC_VERSION}/package.conf.old

.include <bsd.port.mk>
