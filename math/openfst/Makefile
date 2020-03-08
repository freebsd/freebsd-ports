# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.6.3
PORTREVISION=	4
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		compiler:c++11-lib libtool python:2.7
USE_LDCONFIG=	${LOCALBASE}/lib/fst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-bin --enable-compact-fsts --enable-compress --enable-const-fsts --enable-far --enable-linear-fsts --enable-lookahead-fsts --enable-mpdt --enable-ngram-fsts --enable-pdt --enable-python --enable-special
LDFLAGS+=	"-L${LOCALBASE}/lib"
MAKE_ENV+=	PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
