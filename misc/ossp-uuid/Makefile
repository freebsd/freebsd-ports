# Created by: Kimura Fuyuki <fuyuki@nigredo.org>
# $FreeBSD$

PORTNAME=	uuid
PORTVERSION=	1.6.2
PORTREVISION=	8
CATEGORIES=	misc devel
MASTER_SITES=	OSSP/lib/${PORTNAME}
PKGNAMEPREFIX=	ossp-

MAINTAINER=	vd@FreeBSD.org
COMMENT=	ISO-C API and CLI for generating Universally Unique Identifiers

GNU_CONFIGURE=	yes
USES+=		libtool pathfix
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--with-cxx \
		--includedir=${PREFIX}/include/ossp

.if defined(SLAVEPORT) && ${SLAVEPORT}=="perl"
PKGNAMEPREFIX=	p5-OSSP-
.endif

regression-test: test

pre-patch:
### Fixes lib conflicts with misc/e2fsprogs-libuuid ###
	${REINPLACE_CMD} 's/libuuid.la/libossp-uuid.la/ ; s/libuuid++.la/libossp-uuid++.la/' \
		${WRKDIR}/${DISTNAME}/Makefile.in

test: build
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${MAKE_CMD} ${MAKE_FLAGS} \
		${MAKEFILE} ${MAKE_ARGS} check)

.include <bsd.port.mk>
