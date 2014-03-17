# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	6
CATEGORIES=	misc devel
MASTER_SITES=	${MASTER_SITE_OSSP}
MASTER_SITE_SUBDIR=	lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C API and CLI for generating Universally Unique Identifiers

#CONFLICTS=	e2fsprogs-libuuid-[0-9]*

GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-shared --enable-static --with-cxx \
		--includedir=${PREFIX}/include/ossp

.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
PKGNAMEPREFIX=	p5-OSSP-
.endif

.include <bsd.port.pre.mk>

.if ${ARCH} == "amd64" || ${ARCH} == "ia64"
CFLAGS+=	-fPIC -DPIC
.endif

regression-test: test

test: build
	@cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE} ${MAKE_FLAGS} ${MAKEFILE} ${MAKE_ARGS} check

.include <bsd.port.post.mk>
