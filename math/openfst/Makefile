# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.4.1
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

USES=		compiler:c++11-lib libtool
USE_LDCONFIG=	${LOCALBASE}/lib/fst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-compact-fsts --enable-const-fsts --enable-far --enable-linear-fsts --enable-ngram-fsts --enable-lookahead-fsts --enable-pdt

post-patch:
	${REINPLACE_CMD} -e s#-ldl## ${WRKSRC}/src/extensions/far/Makefile.in ${WRKSRC}/src/extensions/pdt/Makefile.in ${WRKSRC}/src/bin/Makefile.in ${WRKSRC}/src/test/Makefile.in ${WRKSRC}/src/extensions/linear/Makefile.in
	${REINPLACE_CMD} -e s#isspace#std::isspace# ${WRKSRC}/src/include/fst/tuple-weight.h ${WRKSRC}/src/include/fst/sparse-tuple-weight.h ${WRKSRC}/src/include/fst/pair-weight.h

.include <bsd.port.mk>
