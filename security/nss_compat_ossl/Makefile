PORTNAME=	nss_compat_ossl
PORTVERSION=	0.9.6
PORTREVISION=	1
CATEGORIES=	security devel
MASTER_SITES=	http://rcritten.fedorapeople.org/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Source-level compatibility library for OpenSSL to NSS porting
WWW=		http://rcritten.fedorapeople.org/nss_compat_ossl.html

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	libnspr4.so:devel/nspr \
		libnss3.so:security/nss

USES=		cpe pkgconfig libtool
CPE_VENDOR=	${PORTNAME}_project
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes

INSTALL_TARGET=	install-strip

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400079 || ( ${OSVERSION} >= 1302505 && ${OSVERSION} < 1400000 ))
CFLAGS+=	-Wno-error=int-conversion
.endif

.include <bsd.port.mk>
