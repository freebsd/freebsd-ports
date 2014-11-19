# $FreeBSD$
PORTNAME=	nss_compat_ossl
PORTVERSION=	0.9.6
MASTER_SITES=	http://rcritten.fedorapeople.org/
CATEGORIES=	security devel

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Source-level compatibility library for OpenSSL to NSS porting

LICENSE=	MIT

GNU_CONFIGURE=	yes
USES=		pkgconfig libtool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

BUILD_DEPENDS=	${LOCALBASE}/lib/nss/libssl3.so:${PORTSDIR}/security/nss
RUN_DEPENDS=	${LOCALBASE}/lib/nss/libssl3.so:${PORTSDIR}/security/nss
LIB_DEPENDS=	libnspr4.so:${PORTSDIR}/devel/nspr

.include <bsd.port.mk>
