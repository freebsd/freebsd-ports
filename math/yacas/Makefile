# ex:ts=8
# New ports collection makefile for:	yacas
# Date created:			Jun 21, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	yacas
PORTVERSION=	1.0.48r1
CATEGORIES=	math
MASTER_SITES=	http://www.xs4all.nl/~apinkus/backups/
DISTNAME=	${PORTNAME}-${PORTVERSION:S/r/rev/}

MAINTAINER=	ports@FreeBSD.org

GNU_CONFIGURE=	yes

.include <bsd.port.pre.mk>

.if defined(WITH_GMP)
.if ${OSVERSION} >= 500000
LIB_DEPENDS+=	gmp.3:${PORTSDIR}/math/libgmp
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"
.endif
CONFIGURE_ARGS+=	--enable-gmp=yes
.endif

.include <bsd.port.post.mk>
