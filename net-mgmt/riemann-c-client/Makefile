# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	riemann-c-client
PORTVERSION=	1.9.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net-mgmt

MAINTAINER=	dch@skunkwerks.at
COMMENT=	C library and command-line tool for Riemann

LICENSE=	LGPL3+

BUILD_DEPENDS=	libcheck>0:devel/libcheck
LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c

USE_GITHUB=	yes
GH_ACCOUNT=	algernon

USES=		autoreconf gmake libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

post-patch:
	@${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/Makefile.am

# Running |make test| isn't on poudriere menu yet, so force-feed
pre-install:	do-test

.include <bsd.port.mk>
