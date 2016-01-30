# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.5.0
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

USES=		compiler:c++11-lib libtool
USE_LDCONFIG=	${LOCALBASE}/lib/fst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-bin --enable-compact-fsts --enable-compress --enable-const-fsts --enable-far --enable-linear-fsts --enable-lookahead-fsts --enable-mpdt --enable-ngram-fsts --enable-pdt

post-patch:
	${REINPLACE_CMD} -e s#-ldl## ${WRKSRC}/src/extensions/far/Makefile.in ${WRKSRC}/src/extensions/pdt/Makefile.in ${WRKSRC}/src/bin/Makefile.in ${WRKSRC}/src/test/Makefile.in ${WRKSRC}/src/extensions/linear/Makefile.in ${WRKSRC}/src/extensions/compress/Makefile.in ${WRKSRC}/src/extensions/mpdt/Makefile.in

.include <bsd.port.mk>
