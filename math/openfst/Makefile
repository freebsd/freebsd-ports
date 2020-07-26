# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	openfst
PORTVERSION=	1.7.9
CATEGORIES=	math
MASTER_SITES=	http://www.openfst.org/twiki/pub/FST/FstDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for working with weighted finite-state transducers (FSTs)

LICENSE=	APACHE20

DEPRECATED=	Uses deprecated version of python
EXPIRATION_DATE=	2020-09-15

USES=		compiler:c++11-lib libtool python:3.6+
USE_LDCONFIG=	${LOCALBASE}/lib/fst
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--enable-bin --enable-compress --enable-python --enable-special --enable-fsts --enable-grm --enable-linear-fsts --enable-ngram-fsts
LDFLAGS+=	"-L${LOCALBASE}/lib"
MAKE_ENV+=	PYTHON=${PYTHON_CMD}

.include <bsd.port.mk>
