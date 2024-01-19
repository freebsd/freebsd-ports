PORTNAME=	ergo
DISTVERSION=	3.8.2
PORTREVISION=	1
CATEGORIES=	science
MASTER_SITES=	http://www.ergoscf.org/source/tarfiles/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Quantum chemistry program for large-scale atomic calculations
WWW=		http://www.ergoscf.org/

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libblas.so:math/blas \
		liblapack.so:math/lapack
TEST_DEPENDS=	bash:shells/bash

USES=		compiler:c++11-lang gmake localbase shebangfix

SHEBANG_FILES=	test/check_eigenvectors.sh test/compare_homo_lumo.sh

GNU_CONFIGURE=	yes

TEST_TARGET=	check

CONFLICTS_INSTALL=	ergo-irc-server # bin/ergo

OPTIONS_DEFINE_amd64=	SSE
OPTIONS_DEFINE_i386=	SSE

SSE_CONFIGURE_ENABLE=	sse-intrinsics

# the lapack_test test fails, reported to the upstream's e-mail

.include <bsd.port.mk>
