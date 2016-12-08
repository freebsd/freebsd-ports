# Created by: Ying-Chieh Liao <ijliao@FreeBSD.org>
# $FreeBSD$

PORTNAME=	domc
PORTVERSION=	0.8.0
PORTREVISION=	4
CATEGORIES=	textproc
MASTER_SITES=	http://www.ioplex.com/~miallen/domc/dl/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Lightweight implementation of the DOM in ANSI C

LICENSE=	MIT

LIB_DEPENDS=	libexpat.so:textproc/expat2 \
		libmba.so:devel/libmba

USES=		gmake
MAKE_ENV=	prefix="${LOCALBASE}" INSTDIR="${STAGEDIR}${PREFIX}"
MAKE_ARGS=	CC="${CC}" RPM_OPT_FLAGS="${CFLAGS}" \
		MAJVERSION=${PORTVERSION:R:R}
CFLAGS+=	-D__USE_XOPEN=__XSI_VISIBLE
USE_LDCONFIG=	yes

.include <bsd.port.mk>
