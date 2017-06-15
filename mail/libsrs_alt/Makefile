# $FreeBSD$

PORTNAME=		libsrs_alt
DISTVERSION=		1.0
PORTREVISION=		2
CATEGORIES=		mail
MASTER_SITES=		http://opsec.eu/src/srs/

MAINTAINER=		pi@FreeBSD.org
COMMENT=		Sender Rewriting Scheme C Implementation

USES=			libtool tar:bzip2
USE_LDCONFIG=		yes
SHLIB_MAJOR=		1
GNU_CONFIGURE=		yes

PLIST_SUB=		SHLIB_MAJOR="${SHLIB_MAJOR}"

OPTIONS_DEFINE=		COMPAT_BASE64
COMPAT_BASE64_DESC=	MTA Friendly base64 compatibility mode

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MCOMPAT_BASE64}
CONFIGURE_ARGS+=	--with-base64compat
.endif

post-patch:
	@${REINPLACE_CMD} -E 's,^(test_LDFLAGS.*$$),\1 -lcompat,' \
		${WRKSRC}/Makefile.in

post-install:
	${MV} ${STAGEDIR}${PREFIX}/bin/srs ${STAGEDIR}${PREFIX}/bin/srs_alt
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/libsrs_alt.so.1.0.0

.include <bsd.port.mk>
