# $FreeBSD$
PORTNAME=	nss_compat_ossl
PORTVERSION=	0.9.6
MASTER_SITES=	http://rcritten.fedorapeople.org/
CATEGORIES=	security devel

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source-level compatibility library for OpenSSL to NSS porting

LICENSE=	MIT

GNU_CONFIGURE=	yes
USES=		pkgconfig libtool
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes

LIB_DEPENDS=	libnspr4.so:${PORTSDIR}/devel/nspr \
		libnss3.so:${PORTSDIR}/security/nss

.include <bsd.port.mk>
