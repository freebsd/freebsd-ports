# New ports collection makefile for:	pure-csv
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-csv
PORTVERSION=	1.4
CATEGORIES=	textproc
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	A CSV reading and writing module for the Pure langauge

LIB_DEPENDS+=	pure:${PORTSDIR}/lang/pure

LICENSE_FILE=	${WRKSRC}/COPYING

PLIST_FILES=	lib/pure/csv.pure \
		lib/pure/csv.so

USE_GCC=	4.2+
USE_GMAKE=	yes

MAKE_ARGS+=	prefix=${PREFIX} CPPFLAGS+=-I${LOCALBASE}/include \
		LDFLAGS+=-L${LOCALBASE}/lib CFLAGS="${CFLAGS}"

.include <bsd.port.mk>
