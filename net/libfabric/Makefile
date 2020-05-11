# $FreeBSD$

PORTNAME=	libfabric
DISTVERSIONPREFIX=	v
DISTVERSION=	1.10.1
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
LDFLAGS+=	${LOCALBASE}/lib/libepoll-shim.so

INSTALL_TARGET=	install-strip

OPTIONS_MULTI=			PROVIDERS
OPTIONS_MULTI_PROVIDERS=	RXD RXM SOCKETS TCP UDP
OPTIONS_DEFAULT=		${OPTIONS_MULTI_PROVIDERS}
OPTIONS_SUB=			yes
PROVIDERS_DESC=			Providers to build:

.if exists(/usr/include/infiniband/verbs.h) # some earlier FreeBSD 11 systems don't have it
OPTIONS_MULTI_PROVIDERS+=	VERBS
VERBS_PLIST_FILES=		man/man7/fi_verbs.7.gz
.endif

.for p in ${OPTIONS_MULTI_PROVIDERS}
${p}_DESC=			'${p:tl}' provider
${p}_CONFIGURE_ENABLE=		${p:tl}
.endfor

SED_WRAP_CLOSE=	{ \
		i\\\n \
		\#ifdef SHIM_SYS_SHIM_HELPERS\\\n \
		\#undef close\\\n \
		\#endif\n \
		a\\\n \
		\#ifdef SHIM_SYS_SHIM_HELPERS\\\n \
		\#define close epoll_shim_close\\\n \
		\#endif\n \
		}

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<asm/types\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<asm/types\.h>|<sys/types.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<malloc\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<malloc\.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<alloca\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<alloca\.h>|<stdlib.h>|'
	@${GREP} -Flr --include='*.c' '.close' ${WRKSRC} | ${XARGS} ${REINPLACE_CMD} $$'/\\.close/${SED_WRAP_CLOSE}'
	@${REINPLACE_CMD} $$'/fi_ops.*close/${SED_WRAP_CLOSE}' ${WRKSRC}/src/fabric.c
	@${REINPLACE_CMD} $$'/[*>]close/${SED_WRAP_CLOSE}' ${WRKSRC}/include/rdma/fabric.h

.include <bsd.port.mk>
