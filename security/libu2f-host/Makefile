# $FreeBSD$

PORTNAME=	libu2f-host
PORTVERSION=	1.1.3
DISTVERSIONPREFIX=	${PORTNAME}-
PORTREVISION=	1
CATEGORIES=	security devel

MAINTAINER=	cpm@FreeBSD.org
COMMENT=	Yubico Universal 2nd Factor (U2F) Host C Library

LICENSE=	LGPL21+ GPLv3+
LICENSE_COMB=	multi

BUILD_DEPENDS=	gengetopt:devel/gengetopt \
		help2man:misc/help2man
LIB_DEPENDS=	libhidapi.so:comms/hidapi \
		libjson-c.so:devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	Yubico

USES=	autoreconf pkgconfig gmake libtool
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes

CONFIGRUE_ARGS=	--disable-gtk-doc
INSTALL_TARGET=	install-strip

SUB_FILES=	pkg-message

GROUPS=	u2f

post-install:
	${INSTALL_DATA} ${FILESDIR}/u2f.conf.sample \
		${STAGEDIR}${PREFIX}/etc/devd

.include <bsd.port.mk>
