# $FreeBSD$

PORTNAME=	libfabric
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.0rc3-281
DISTVERSIONSUFFIX=	-g85a686840
CATEGORIES=	net

PATCH_SITES=	https://github.com/${GH_ACCOUNT}/${PORTNAME}/commit/
PATCHFILES=	a088f58fac6708b42b810f3746f538ab7452eeb2.patch:-p1

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

post-patch:
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<asm/types\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<asm/types\.h>|<sys/types.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<malloc\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<malloc\.h>|<stdlib.h>|'
	@${FIND} ${WRKSRC} -name "*.[ch]" -and -exec ${GREP} -q '<alloca\.h>' {} \; -print | ${XARGS} ${REINPLACE_CMD} 's|<alloca\.h>|<stdlib.h>|'

.include <bsd.port.mk>
