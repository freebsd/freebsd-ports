PORTNAME=	perp
PORTVERSION=	2.07
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES =	http://b0llix.net/perp/distfiles/

MAINTAINER=	ports@jpmens.net
COMMENT=	Persistent process supervisor and service management framework
WWW=		http://b0llix.net/perp/

LICENSE=	UNKNOWN
LICENSE_NAME=	unknown
LICENSE_FILE=	${WRKSRC}/LICENSE
LICENSE_PERMS=	dist-mirror dist-sell pkg-mirror pkg-sell auto-accept

CFLAGS+=	-I. -I../lasagna \
		-DPERP_BASE_DEFAULT='\"${PREFIX}/etc/perp\"'
MAKE_ARGS+=	CC="${CC}" CFLAGS="${CFLAGS}" \
		BINDIR=${PREFIX}/bin SBINDIR=${PREFIX}/sbin MANDIR=${PREFIX}/share/man

pre-install:
	cd ${WRKSRC} && ${MAKE} strip

.include <bsd.port.mk>
