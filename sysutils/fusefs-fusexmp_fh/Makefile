# Created by: buganini@gmail.com
# $FreeBSD$

PORTNAME=	fusexmp_fh
PORTVERSION=	2.9.3
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Dummy driver from fusefs-libs example

USE_AUTOTOOLS=	libtool
USES=		fuse pathfix iconv
USE_LDCONFIG=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kernel-module --prefix=${PREFIX} \
		--enable-example

PLIST_FILES=	bin/${PORTNAME}

NO_STAGE=	yes
do-build:
	cd ${WRKSRC}/lib \
	&& ${MAKE}
	cd ${WRKSRC}/example \
	&& ${MAKE} ${PORTNAME}

do-install:
	cd ${WRKSRC}/example/.libs \
	&& ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
