# ex:ts=8
# New ports collection makefile for:	rpc
# Date created:			Mar 21, 2001
# Whom:				Ying-Chieh Liao <ijliao@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	rpc
PORTVERSION=	0.96
CATEGORIES=	math
MASTER_SITES=	http://www.eecs.umich.edu/~pelzlpj/rpc/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath
RUN_DEPENDS=	${LOCALBASE}/lib/libccm.so:${PORTSDIR}/math/ccmath

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CXXFLAGS} -I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
USE_GMAKE=	yes

.include <bsd.port.mk>
