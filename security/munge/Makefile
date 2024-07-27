PORTNAME=	munge
DISTVERSION=	0.5.16
CATEGORIES=	security
MASTER_SITES=	https://github.com/dun/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Authentication service for creating and validating credentials
WWW=		https://dun.github.io/munge/

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

LIB_DEPENDS=	libgcrypt.so:security/libgcrypt

USES=		cpe libtool pathfix ssl tar:xz
CPE_VENDOR=	opensuse
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-prefix=${OPENSSLBASE}

INSTALL_TARGET=	install-strip
TEST_TARGET=	check

.include <bsd.port.mk>
