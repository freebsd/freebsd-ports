PORTNAME=	GiNaC
PORTVERSION=	1.8.3
CATEGORIES=	math
MASTER_SITES=	ftp://ftpthep.physik.uni-mainz.de/pub/GiNaC/ \
		http://www.ginac.de/
DISTNAME=	${PORTNAME:tl}-${PORTVERSION}

MAINTAINER=	stephen@FreeBSD.org
COMMENT=	C++ library for symbolic mathematical calculations

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libcln.so:math/cln

USES=		compiler:c++11-lib gmake libtool makeinfo ncurses pathfix \
		pkgconfig python:build readline tar:bzip2
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

INFO=		ginac ginac-examples

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-ldl||g' ${WRKSRC}/configure
.if ${ARCH} != "i386"
	@${REINPLACE_CMD} -e 's|unsigned|size_t|g' \
		${WRKSRC}/ginac/parser/parser.cpp
.endif

.include <bsd.port.post.mk>
