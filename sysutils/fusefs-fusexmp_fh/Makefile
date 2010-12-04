# New ports collection makefile for:    fusefs-fusexmp_fh
# Date created:         22 August 2010
# Whom:                 buganini@gmail.com
# $FreeBSD$
#

PORTNAME=	fusexmp_fh
PORTVERSION=	2.7.4
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SF/fuse/fuse-2.X/${PORTVERSION}
PKGNAMEPREFIX=	fusefs-
DISTNAME=	fuse-${PORTVERSION}

MAINTAINER=	buganini@gmail.com
COMMENT=	Dummy driver from fusefs-libs example

LIB_DEPENDS=	fuse.2:${PORTSDIR}/sysutils/fusefs-libs
RUN_DEPENDS=	${LOCALBASE}/modules/fuse.ko:${PORTSDIR}/sysutils/fusefs-kmod

USE_AUTOTOOLS=	libtool
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
USE_ICONV=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--disable-kernel-module --prefix=${PREFIX} \
		--enable-example

PLIST_FILES=	bin/${PORTNAME}

post-patch:
	${REINPLACE_CMD} -e 's,-lpthread,${PTHREAD_LIBS},' \
		${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/example/Makefile.in

do-build:
	cd ${WRKSRC}/lib \
	&& ${MAKE}
	cd ${WRKSRC}/example \
	&& ${MAKE} ${PORTNAME}

do-install:
	cd ${WRKSRC}/example/.libs \
	&& ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
