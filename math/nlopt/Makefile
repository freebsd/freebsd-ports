# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	nlopt
PORTVERSION=	2.4.2
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/nlopt/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Nonlinear optimization library

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:${PORTSDIR}/math/gmp \
		libguile.so:${PORTSDIR}/lang/guile
BUILD_DEPENDS=	swig2.0:${PORTSDIR}/devel/swig20 \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.8.1:${PORTSDIR}/math/py-numpy
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.8.1:${PORTSDIR}/math/py-numpy

CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig2.0"

USES=		autoreconf compiler:features libtool pathfix \
		pkgconfig python:2
USE_AUTOTOOLS=	libtoolize
USE_LDCONFIG=	yes

PATHFIX_MAKEFILEIN=	Makefile.am

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
