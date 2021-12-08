PORTNAME=	spot
DISTVERSION=	2.10.2
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for omega automata manipulation and model checking

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix compiler:c++14-lang gmake libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-python --disable-static

INSTALL_TARGET=	install-strip

OPTIONS_DEFINE=	DOCS

PORTDOCS=	tl.pdf

TEST_TARGET=	check

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
