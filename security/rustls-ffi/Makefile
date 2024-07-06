PORTNAME=	rustls-ffi
PORTVERSION=	0.13.0
DISTVERSIONPREFIX=	v
CATEGORIES=	security

MAINTAINER=	brnrd@FreeBSD.org
COMMENT=	FFI bindings for the rustls TLS library
WWW=		https://github.com/rustls/rustls-ffi

LICENSE=	APACHE20 ISCL MIT
LICENSE_COMB=	dual
LICENSE_FILE_APACHE20=	${WRKSRC}/LICENSE-APACHE
LICENSE_FILE_ISCL=	${WRKSRC}/LICENSE-ISC
LICENSE_FILE_MIT=	${WRKSRC}/LICENSE-MIT

USES=		cargo gmake

USE_GITHUB=	yes
GH_ACCOUNT=	rustls

PLIST_FILES=	include/rustls.h \
		lib/librustls.a

do-build:
	${MAKE_CMD} -C ${WRKSRC}

do-install:
	${MAKE_CMD} -C ${WRKSRC} DESTDIR=${STAGEDIR}/${PREFIX} install

.include <bsd.port.mk>
