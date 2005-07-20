# ex:ts=8
# Ports collection makefile for:	libecc
# Date created:			Oct 29, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	libecc
PORTVERSION=	0.11.0
CATEGORIES=	security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	C++ Elliptic Curve Library

LIB_DEPENDS=	gmp.6:${PORTSDIR}/math/libgmp4

USE_GCC=	3.3+
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes

CONFIGURE_ENV+=	LDFLAGS="-L${PREFIX}/lib -L${LOCALBASE}/lib" \
		CPPFLAGS="-I${PREFIX}/include -I${LOCALBASE}/include"

.include <bsd.port.pre.mk>

.if ${ARCH} != "i386"
BROKEN=		"Does not compile on !i386"
.endif

.if ${OSVERSION} < 501103
# Work around bsd.port.mk bug: Does not currently set up MAKE_ENV for gcc 3.2 and 3.3
MAKE_ENV+=	CC="${CC}" CXX="${CXX}"
.endif

.include <bsd.port.post.mk>
