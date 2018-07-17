# Created by: Dmitry Sivachenko <mitya@yandex-team.ru>
# $FreeBSD$

PORTNAME=	hfst
PORTVERSION=	3.13.0
PORTREVISION=	2
CATEGORIES=	math

MAINTAINER=	demon@FreeBSD.org
COMMENT=	Toolkit for for processing natural language morphologies

BROKEN=		fails to build: /usr/bin/byacc: e - line 75 of "/wrkdirs/usr/ports/math/hfst/work/hfst-c187d5a/libhfst/src/parsers/xre_parse.yy", syntax error
DEPRECATED=	Broken for more than 5 months
EXPIRATION_DATE=	2018-08-20

USE_GITHUB=	yes
GH_TAGNAME=	c187d5a

USES=		autoreconf libtool pathfix pkgconfig python:2.7 readline shebangfix
USE_GCC=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-readline --enable-lexc-wrapper --enable-proc --enable-tagger --enable-train-tagger --enable-xfst --enable-shuffle --enable-traverse
CPPFLAGS+=	-I${LOCALBASE}/include -I${LOCALBASE}/include/libxml2
LDFLAGS+=	-L${LOCALBASE}/lib
SHEBANG_FILES=	tools/src/hfst-tagger/src/hfst_tagger_compute_data_statistics.py
USE_LDCONFIG=	yes

.include <bsd.port.mk>
