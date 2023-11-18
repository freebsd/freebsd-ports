PORTNAME=	pftop
PORTVERSION=	0.10
CATEGORIES=	sysutils net

MAINTAINER=	grembo@FreeBSD.org
COMMENT=	Utility for real-time display of statistics for pf
WWW=		https://github.com/grembo/pftop/

LICENSE=	BSD2CLAUSE

LIB_DEPENDS=	libpfctl.so:net/libpfctl

USES=		localbase uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	grembo

OPTIONS_DEFINE=	ALTQ

ALTQ_DESC=	ALTQ support for queue statistics

.include <bsd.port.options.mk>

MAKE_ARGS=	LOCALBASE="${PREFIX}"

CFLAGS+=	-DHAVE_SNPRINTF=1 -DHAVE_VSNPRINTF=1

.if ${PORT_OPTIONS:MALTQ}
CFLAGS+=	-DHAVE_ALTQ=1
.endif

MAKE_ARGS+=	CSTD=gnu89
MAKE_ENV+=	__MAKE_CONF=/dev/null

PLIST_FILES=	man/man8/pftop.8.gz \
		sbin/pftop

.include <bsd.port.mk>
