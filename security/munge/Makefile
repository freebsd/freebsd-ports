# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	munge
PORTVERSION=	0.5.12
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Authentication service for creating and validating credentials

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

USE_GITHUB=yes
GH_ACCOUNT=	dun
GH_TAGNAME=	880584f

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-prefix=${OPENSSLBASE}
USES=		libtool pathfix perl5 ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged
INSTALL_TARGET=	install-strip

.include <bsd.port.mk>
