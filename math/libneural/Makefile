# Created by: will
# $FreeBSD$

PORTNAME=	libneural
PORTVERSION=	1.0.3
PORTREVISION=	2
CATEGORIES=	math devel
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ implementation of the classic 3-layer perceptron in library form

BROKEN=		unfetchable
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2016-07-04

USES=		libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip

post-patch:
	@${REINPLACE_CMD} -e 's|iostream.h|iostream|; s|fstream.h|fstream|; s|iomanip.h|iomanip|; \
		s|endl|std::&|g; s|cerr|std::&|g; s|cout|std::&|g; s|cin|std::&|g; s|[oi]fstream |std::&|g' \
		${WRKSRC}/lib/neuron.cc ${WRKSRC}/lib/nnwork.cc ${WRKSRC}/examples/*.cc

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libneural.so

.include <bsd.port.mk>
