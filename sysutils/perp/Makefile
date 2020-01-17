# $FreeBSD$

PORTNAME=	perp
PORTVERSION=	2.07
CATEGORIES=	sysutils
MASTER_SITES =	http://b0llix.net/perp/distfiles/

MAINTAINER=	ports@jpmens.net
COMMENT=	Persistent process supervisor & service managment framework for un!x

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CFLAGS+=	-I. -I../lasagna \
		-DPERP_BASE_DEFAULT='\"${PREFIX}/etc/perp\"'
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" \
		BINDIR=${PREFIX}/bin SBINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/man

pre-install:
	cd ${WRKSRC} && ${MAKE} strip

.include <bsd.port.mk>
