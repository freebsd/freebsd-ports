# $FreeBSD$

PORTNAME=	spot
DISTVERSION=	2.8.3
CATEGORIES=	math
MASTER_SITES=	http://www.lrde.epita.fr/dload/${PORTNAME}/

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Library for omega automata manipulation and model checking

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		charsetfix compiler:c++14-lang gmake libtool
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-python --disable-static
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

OPTIONS_DEFINE=	DOCS

PORTDOCS=	tl.pdf

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/*.so

.include <bsd.port.mk>
