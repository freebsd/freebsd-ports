# Created by: will
# $FreeBSD$

PORTNAME=	libneural
PORTVERSION=	1.0.3
PORTREVISION=	1
CATEGORIES=	math devel
MASTER_SITES=	http://www.freebsdbrasil.com.br/~jmelo/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ implementation of the classic 3-layer perceptron in library form

USE_AUTOTOOLS=	libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|$${CONFIG_SHELL-/bin/sh} $$ac_aux_dir|$$ac_aux_dir|' \
		${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|iostream.h|iostream|; s|fstream.h|fstream|; s|iomanip.h|iomanip|; \
		s|endl|std::&|g; s|cerr|std::&|g; s|cout|std::&|g; s|cin|std::&|g; s|[oi]fstream |std::&|g' \
		${WRKSRC}/lib/neuron.cc ${WRKSRC}/lib/nnwork.cc ${WRKSRC}/examples/*.cc

.include <bsd.port.mk>
