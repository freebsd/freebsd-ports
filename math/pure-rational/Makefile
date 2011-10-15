# New ports collection makefile for:	pure-rational
# Date created:		2011-10-09
# Whom:			Zhihao Yuan <lichray@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	pure-rational
PORTVERSION=	0.1
CATEGORIES=	math
MASTER_SITES=	http://pure-lang.googlecode.com/files/

MAINTAINER=	lichray@gmail.com
COMMENT=	Rational number library for the Pure language

LIB_DEPENDS+=	pure:${PORTSDIR}/lang/pure

LICENSE=	GPLv3

PLIST_FILES=	lib/pure/rational.pure \
		lib/pure/rat_interval.pure

USE_GMAKE=	yes

MAKE_ARGS+=	prefix=${PREFIX}

.include <bsd.port.mk>
