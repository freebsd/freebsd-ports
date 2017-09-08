# Created by: Dave Cottlehuber <dch@skunkwerks.at>
# $FreeBSD$

PORTNAME=	riemann-c-client
PORTVERSION=	1.10.1
DISTVERSIONPREFIX=	${PORTNAME}-
CATEGORIES=	net-mgmt

MAINTAINER=	dch@skunkwerks.at
COMMENT=	C library and command-line tool for Riemann

LICENSE=	LGPL3+
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	check>0:devel/check
LIB_DEPENDS=	libprotobuf-c.so:devel/protobuf-c \
		libgnutls.so:security/gnutls \
		libjson-c.so:devel/json-c

USES=		autoreconf gmake libtool pathfix pkgconfig

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
INSTALL_TARGET=	install-strip
TEST_TARGET=	check

USE_GITHUB=	yes
GH_ACCOUNT=	algernon

MAKE_JOBS_UNSAFE=	yes

post-patch:
	@${REINPLACE_CMD} 's/-ldl//' ${WRKSRC}/Makefile.am

# Running |make test| isn't on poudriere menu yet, so force-feed
pre-install:	do-test

.include <bsd.port.mk>
