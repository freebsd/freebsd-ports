# Created by: Rainer Hurling <rhurlin@gwdg.de>
# $FreeBSD$

PORTNAME=	nlopt
PORTVERSION=	2.4.2
PORTREVISION=	1
CATEGORIES=	math
MASTER_SITES=	http://ab-initio.mit.edu/nlopt/

MAINTAINER=	rhurlin@gwdg.de
COMMENT=	Nonlinear optimization library

LICENSE=	LGPL21 MIT
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libgmp.so:math/gmp \
		libguile-2.0.so:lang/guile2
BUILD_DEPENDS=	swig3.0:devel/swig30 \
		${PYTHON_PKGNAMEPREFIX}numpy>=1.9.1,1:math/py-numpy@${PY_FLAVOR}
RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.9.1,1:math/py-numpy@${PY_FLAVOR}

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--enable-shared
CONFIGURE_ENV=	SWIG="${LOCALBASE}/bin/swig3.0"

USES=		autoreconf compiler:features libtool pathfix \
		pkgconfig python:2
USE_LDCONFIG=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
