# Created by: thierry@pompo.net

PORTNAME=	pynac
PORTVERSION=	0.7.29
PORTREVISION=	1
CATEGORIES=	math python
MASTER_SITES=	https://github.com/${PORTNAME}/${PORTNAME}/archive/

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	Symbolic computation with Python objects, Sage Math support library

LICENSE=	GPLv2

LIB_DEPENDS=	libgmp.so:math/gmp		\
		libntl.so:math/ntl		\
		libmpfr.so:math/mpfr		\
		libflint.so:math/flint2		\
		libSingular.so:math/singular

USES=		autoreconf compiler:c++11-lang libtool localbase pkgconfig	\
		python:3.6+

OPTIONS_DEFINE=		GIAC
OPTIONS_DEFAULT=
GIAC_DESC=		Use giac for polynomial manipulations
GIAC_LIB_DEPENDS=	libgiac.so:math/giacxcas
GIAC_CONFIGURE_ON=	--with-giac
GIAC_CONFIGURE_OFF=	--without-giac
GIAC_LIBS=		"-lm"

GNU_CONFIGURE=	yes
WRKSRC=		${WRKDIR}/${PORTNAME}-${PORTNAME}-${PORTVERSION}
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
