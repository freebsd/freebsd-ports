# Created by: Muhammad Moinur Rahman <5u623l20@gmail.com>
# $FreeBSD$

PORTNAME=	munge
PORTVERSION=	0.5.14
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	security

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Authentication service for creating and validating credentials

LICENSE=	GPLv3 LGPL3
LICENSE_COMB=	dual

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-openssl-prefix=${OPENSSLBASE}
USES=		autoreconf libtool pathfix perl5 ssl
USE_LDCONFIG=	yes
USE_RC_SUBR=	munged
INSTALL_TARGET=	install-strip

USE_GITHUB=	yes
GH_ACCOUNT=	dun

.include <bsd.port.mk>
