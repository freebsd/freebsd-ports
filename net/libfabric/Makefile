# $FreeBSD$

PORTNAME=	libfabric
DISTVERSIONPREFIX=	v
DISTVERSION=	1.6.2
CATEGORIES=	net

MAINTAINER=	yuri@FreeBSD.org
COMMENT=	Open Fabric Interfaces

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libepoll-shim.so:devel/libepoll-shim

USES=		autoreconf gmake libtool pkgconfig
USE_GITHUB=	yes
GH_ACCOUNT=	ofiwg
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-static
USE_LDCONFIG=	yes

CFLAGS+=	-I${LOCALBASE}/include/libepoll-shim
LDFLAGS+=	${LOCALBASE}/lib/libepoll-shim.so -pthread

OPTIONS_DEFINE=		VERBS
OPTIONS_SUB=		yes

VERBS_DESC=		Build 'verbs' provider
VERBS_CONFIGURE_ENABLE=	verbs

.if exists(/usr/include/infiniband/verbs.h) # some earlier FreeBSD 11 systems don't have it
OPTIONS_DEFAULT+=	VERBS
.else
VERBS_BROKEN=		infiniband/verbs.h not available on your system
.endif

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<asm/types\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<asm/types\.h>|<sys/types.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<malloc\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<malloc\.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<alloca\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<alloca\.h>|<stdlib.h>|'

.include <bsd.port.mk>
