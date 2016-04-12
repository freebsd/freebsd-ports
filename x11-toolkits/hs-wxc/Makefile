# $FreeBSD$

PORTNAME=	wxc
PORTVERSION=	0.91.0.0
CATEGORIES=	x11-toolkits haskell

MAINTAINER=	haskell@FreeBSD.org
COMMENT=	wxHaskell C++ wrapper

USE_CABAL=	wxdirect>=0.91

USES=		dos2unix
USE_WX=		3.0
WX_COMPS=	wx
WX_UNICODE=	yes

OPTIONS_EXCLUDE=DOCS

post-patch::
	@${REINPLACE_CMD} 's|"wx-config"|"wxgtk2u-3.0-config"| ; \
	    s|/sbin/ldconfig -n|/sbin/ldconfig -m| ; \
	    s|"2.9"|"3.0"|' \
	    ${WRKSRC}/Setup.hs

.include "${.CURDIR}/../../lang/ghc/bsd.cabal.mk"

.if ${PORT_OPTIONS:MPCLANG} || ${PORT_OPTIONS:MBCLANG}
LIB_DEPENDS+=	libc++.so.1:devel/libc++

.if ${OSVERSION} < 1000000
CONFIGURE_ARGS+=	--extra-include-dirs=${LOCALBASE}/include/c++/v1
.endif
.endif

.include <bsd.port.mk>
