# Created by: thierry@pompo.net
# $FreeBSD$

PORTNAME=	pynac
PORTVERSION=	0.7.26
PORTREVISION=	2
CATEGORIES=	math python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/releases/download/${DISTNAME}/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Symbolic computation with Python objects, Sage Math support library

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp		\
		libntl.so:math/ntl		\
		libflint.so:math/flint2		\
		libSingular.so:math/singular

USES=		compiler:c++11-lang libtool localbase pkgconfig python:3.6+ tar:bz2

OPTIONS_DEFINE=		GIAC
OPTIONS_DEFAULT=
GIAC_DESC=		Use giac for polynomial manipulations
GIAC_LIB_DEPENDS=	libgiac.so:math/giacxcas
GIAC_CONFIGURE_ON=	--with-giac
GIAC_CONFIGURE_OFF=	--without-giac
GIAC_LIBS=		"-lm"

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
TEST_TARGET=	check

pre-configure-GIAC-on:
	${REINPLACE_CMD} -e 's|-lpynac|-lpynac -lgiac|' ${WRKSRC}/pynac.pc.in

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGIAC}
BROKEN_FreeBSD_11=	libgiac is broken (undefined reference to `__divmodti4@GCC_7.0.0')
.endif

.include <bsd.port.mk>
