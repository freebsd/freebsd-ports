PORTNAME=		libsrs_alt
DISTVERSION=		1.0
PORTREVISION=		3
CATEGORIES=		mail
MASTER_SITES=		http://opsec.eu/src/srs/

MAINTAINER=		pi@FreeBSD.org
COMMENT=		Sender Rewriting Scheme C Implementation
WWW=			https://opsec.eu/src/srs/

LICENSE=		GPLv2
LICENSE_FILE=		${WRKSRC}/COPYING

USES=			libtool tar:bzip2
USE_LDCONFIG=		yes

GNU_CONFIGURE=		yes
LIBS+=			-lutil

PLIST_SUB=		SHLIB_MAJOR="${SHLIB_MAJOR}"

OPTIONS_DEFINE=		COMPAT_BASE64

COMPAT_BASE64_DESC=	MTA Friendly base64 compatibility mode

COMPAT_BASE64_CONFIGURE_ON=	--with-base64compat

SHLIB_MAJOR=		1

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD
CFLAGS+=	-Wno-error=incompatible-function-pointer-types
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,^(test_LDFLAGS.*$$),\1 -lcompat,' \
		${WRKSRC}/Makefile.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/srs ${STAGEDIR}${PREFIX}/bin/srs_alt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsrs_alt.so.1.0.0

.include <bsd.port.mk>
