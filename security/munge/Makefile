PORTNAME=	munge
DISTVERSION=	0.5.14
PORTREVISION=	1
CATEGORIES=	security
MASTER_SITES=	https://github.com/dun/${PORTNAME}/releases/download/${PORTNAME}-${DISTVERSION}/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Authentication service for creating and validating credentials

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USES=		cpe libtool pathfix perl5 ssl tar:xz
CPE_VENDOR=	opensuse
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

USE_RC_SUBR=	munged

INSTALL_TARGET=	install-strip

CONFIGURE_ARGS=	--with-openssl-prefix=${OPENSSLBASE}

.include <bsd.port.mk>
