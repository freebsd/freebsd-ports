# New ports collection makefile for:	pure-csv
# Date created:		2011-03-18
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-csv
PORTVERSION=	1.5
CATEGORIES=	textproc

MAINTAINER=	lichray@gmail.com
COMMENT=	A CSV reading and writing module for the Pure language

USE_PURE=	yes
NO_PURE_EXAMPLES=	yes

PLIST_FILES=	lib/pure/csv.pure \
		lib/pure/csv.so

.include <bsd.port.pre.mk>
.include "${PORTSDIR}/lang/pure/bsd.pure.mk"
.include <bsd.port.post.mk>
