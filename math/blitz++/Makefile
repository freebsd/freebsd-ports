# ex:ts=8
# Ports collection makefile for:	blitz++
# Date created:			Jul 25, 2002
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	blitz++
PORTVERSION=	0.6
CATEGORIES=	math
MASTER_SITES=	http://www.oonumerics.org/blitz/download/releases/
DISTNAME=	blitz-${PORTVERSION:S/b/beta/}

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	blas:${PORTSDIR}/math/blas

USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	LDFLAGS="-lg2c"
CONFIGURE_ARGS=	--with-cxx=gcc --with-blas=${LOCALBASE}/lib \
		--enable-optimize --disable-debug
USE_GMAKE=	yes

post-patch:
	@${FIND} ${WRKSRC}/manual -name "Makefile.in" | ${XARGS} \
		${REINPLACE_CMD} -e "s,[$$][(]prefix[)],\$$(datadir),"

.include <bsd.port.mk>
