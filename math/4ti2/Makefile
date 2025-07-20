PORTNAME=	4ti2
DISTVERSIONPREFIX=	Release_
DISTVERSION=	1_6_13
CATEGORIES=	math

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Solve algebraic, geometric, combinatorial problems on linear spaces
WWW=		https://4ti2.github.io/

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libglpk.so:math/glpk \
		libgmp.so:math/gmp

USES=		autoreconf compiler:c++11-lang gmake libtool shebangfix
USE_GITHUB=	yes
USE_LDCONFIG=	yes

SHEBANG_FILES=	test/check.template.in

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static --enable-shared --with-glpk=${LOCALBASE} --with-gmp=${LOCALBASE}

INSTALL_TARGET=	install-strip

TEST_TARGET=	check # tests fail to run: https://github.com/4ti2/4ti2/issues/26

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
