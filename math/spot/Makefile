PORTNAME=	spot
DISTVERSION=	2.14.3
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for omega automata manipulation and model checking
WWW=		https://spot.lrde.epita.fr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

TEST_DEPENDS=	${PYNUMPY} \
		${PYTHON_PKGNAMEPREFIX}pandas>0:math/py-pandas@${PY_FLAVOR} \
		syfco:math/hs-syfco

USES=		charsetfix compiler:c++17-lang gmake libtool python:test
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
GNU_CONFIGURE_MANPREFIX=	${PREFIX}/share
.if !defined(WITH_PYTHON) # math/py-spot is a separate port but tests don't work there. To test run: make test WITH_PYTHON=yes
CONFIGURE_ARGS=	--disable-python --disable-static
.else
CONFIGURE_ARGS=	--disable-static
.endif

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

OPTIONS_DEFINE=	DOCS

PORTDOCS=	tl.pdf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
