# Created by: b.f. <bf@FreeBSD.org>
# $FreeBSD$

PORTNAME=	fflas-ffpack
PORTVERSION=	2.4.3
PORTREVISION=	1
CATEGORIES=	math

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Library for dense linear algebra over word-size finite fields

LICENSE=	LGPL21

BUILD_DEPENDS=	bash:shells/bash
LIB_DEPENDS=	libgmp.so:math/gmp	\
		libgivaro.so:math/givaro
RUN_DEPENDS=	bash:shells/bash

USE_GITHUB=	yes
GH_ACCOUNT=	linbox-team

USES=		autoreconf blaslapack:openblas compiler:c++11-lang gmake	\
		libtool localbase pkgconfig shebangfix
GNU_CONFIGURE=	yes
SHEBANG_FILES=	fflas-ffpack-config.in
TEST_TARGET=	check

OPTIONS_DEFINE=	DOXYGEN

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDOXYGEN}
BUILD_DEPENDS+=		doxygen:devel/doxygen
CONFIGURE_ARGS+=	--enable-doc --with-docdir="${DOCSDIR}"
PLIST_SUB+=	DOXYGEN=""
.else
PLIST_SUB+=	DOXYGEN="@comment "
.endif

post-patch-DOXYGEN-on:
	${REINPLACE_CMD} -e 's/sed -i/& ""/' ${WRKSRC}/doc/Makefile.am

post-install-DOXYGEN-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/fflas-ffpack-dev-html
	@${TOUCH} ${STAGEDIR}${DOCSDIR}/fflas-ffpack-dev-html/.keep-me

.include <bsd.port.mk>
