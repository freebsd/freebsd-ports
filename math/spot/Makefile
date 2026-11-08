PORTNAME=	spot
DISTVERSION=	2.16.1
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for omega automata manipulation and model checking
WWW=		https://spot.lrde.epita.fr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}numpy>=1.16:math/py-numpy@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		gawk:lang/gawk \
		gcut:sysutils/coreutils

USES=		charsetfix compiler:c++17-lang gmake libtool python:test
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
CONFIGURE_ARGS=	AWK=${LOCALBASE}/bin/gawk
.if !defined(WITH_PYTHON) # math/py-spot is a separate port but tests don't work there. To test run: make test WITH_PYTHON=yes
CONFIGURE_ARGS+=	--disable-python --disable-static
.else
CONFIGURE_ARGS+=	--disable-static
.endif

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

PORTDOCS=	tl.pdf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

# below failures were reported to then upstream @ spot@lrde.epita.fr on 2026-10-24
# ============================================================================
# Testsuite summary for spot 2.16.1
# ============================================================================
# TOTAL: 218
# PASS:  187
# SKIP:  21
# XFAIL: 0
# FAIL:  10
# XPASS: 0
# ERROR: 0

.include <bsd.port.mk>
