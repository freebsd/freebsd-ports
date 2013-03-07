# Created by: Simon Dick <simond@irrelevant.org>
# $FreeBSD$

PORTNAME=		libsrs_alt
DISTVERSION=		1.0
CATEGORIES=		mail
MASTER_SITES=		http://srs.mirtol.com/

MAINTAINER=		simond@irrelevant.org
COMMENT=		Sender Rewriting Scheme C Implementation

USE_AUTOTOOLS=	libtool
USE_BZIP2=		yes
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

.include <bsd.port.mk>
