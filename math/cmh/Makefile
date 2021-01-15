# $FreeBSD$

PORTNAME=	cmh
DISTVERSION=	1.0.20200923
CATEGORIES=	math
#MASTER_SITES=	http://www.multiprecision.org/downloads/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Compute Igusa class polynomials

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libfplll.so:math/fplll \
		libgmp.so:math/gmp \
		libmpc.so:math/mpc \
		libmpfr.so:math/mpfr \
		libmpfrcx.so:math/mpfrcx \
		libpari.so:math/pari
RUN_DEPENDS=	bash:shells/bash

USES=		autoreconf gmake libtool localbase shebangfix
USE_LDCONFIG=	yes

USE_GITLAB=	yes
GL_SITE=	https://gitlab.inria.fr/
GL_COMMIT=	53bba6332e8df9d30ed9bb839bd78afe6aa60153

SHEBANG_FILES=	scripts/cmh-classpol.sh.in

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

INFO=		cm

.include <bsd.port.mk>
