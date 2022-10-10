PORTNAME=	spot
DISTVERSION=	2.11.1
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for omega automata manipulation and model checking
WWW=		https://spot.lrde.epita.fr

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix compiler:c++17-lang gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
.if !defined(WITH_PYTHON) # math/py-spot is a separate port but tests don't work there. To test run: make test WITH_PYTHON=yes
CONFIGURE_ARGS=	--disable-python --disable-static
.else
CONFIGURE_ARGS=	--disable-static
.endif

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	tl.pdf

TEST_TARGET=	check # at least one test fails to run, see https://gitlab.lre.epita.fr/spot/spot/-/issues/517

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
