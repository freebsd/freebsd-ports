# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.5.1
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

BROKEN_powerpc64=	Does not build

USES=		compiler:c++11-lib libtool
USE_LDCONFIG=	${LOCALBASE}/lib/fst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-bin --enable-compact-fsts --enable-compress --enable-const-fsts --enable-far --enable-linear-fsts --enable-lookahead-fsts --enable-mpdt --enable-ngram-fsts --enable-pdt

.include <bsd.port.mk>
