# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	opengrm-ngram
PORTVERSION=	1.2.2
CATEGORIES=	textproc
MASTER_SITES=	http://openfst.cs.nyu.edu/twiki/pub/GRM/NGramDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for making n-gram language models encoded as weighted FSTs

LICENSE=	APACHE20

LIB_DEPENDS=	libfst.so:math/openfst

USES=		compiler:c++11-lib libtool
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.include <bsd.port.mk>
