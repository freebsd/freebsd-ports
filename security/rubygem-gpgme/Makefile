PORTNAME=	gpgme
PORTVERSION=	2.0.22
CATEGORIES=	security rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Ruby interface to GnuPG Made Easy (GPGME)
WWW=		https://github.com/ueno/ruby-gpgme

LICENSE=	LGPL21+

BUILD_DEPENDS=	gpgme>=1.1.2:security/gpgme \
		libassuan>=2.5.5:security/libassuan \
		libgpg-error>=1.45:security/libgpg-error
LIB_DEPENDS=	libassuan.so:security/libassuan \
		libgpg-error.so:security/libgpg-error \
		libgpgme.so:security/gpgme

USES=		gem pkgconfig shebangfix
SHEBANG_FILES=	test/pinentry

CONFIGURE_ARGS=	--use-system-libraries

.include <bsd.port.options.mk>

.if ${OPSYS} == FreeBSD && ( ${OSVERSION} >= 1400091 || ( ${OSVERSION} >= 1302507 && ${OSVERSION} < 1400000 ))
CONFIGURE_ARGS+=	--with-cflags="-Wno-error=incompatible-function-pointer-types"
.endif

.include <bsd.port.mk>
