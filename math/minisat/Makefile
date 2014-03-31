# Created by: Vsevolod Stakhov <vsevolod@FreeBSD.org>
# $FreeBSD$

PORTNAME=	minisat
PORTVERSION=	2.2.1
CATEGORIES=	math devel
MASTER_SITES=	http://highsecure.ru/distfiles/

MAINTAINER=	vsevolod@FreeBSD.org
COMMENT=	A minimalistic, open-source SAT solver

USES=	gmake
USE_LDCONFIG=	yes
MAKE_ENV=	prefix=${PREFIX} CFLAGS="-std=c++03"

.include <bsd.port.mk>
