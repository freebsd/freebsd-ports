# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	opengrm-ngram
PORTVERSION=	1.3.1
PORTREVISION=	2
CATEGORIES=	textproc
MASTER_SITES=	http://openfst.cs.nyu.edu/twiki/pub/GRM/NGramDownload/

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Library for making n-gram language models encoded as weighted FSTs

LICENSE=	APACHE20

BROKEN=		fails to build
DEPRECATED=	Broken for more than 6 months
EXPIRATION_DATE=	2018-06-06

LIB_DEPENDS=	libfst.so:math/openfst

USES=		compiler:c++11-lib libtool localbase
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes

.include <bsd.port.mk>
