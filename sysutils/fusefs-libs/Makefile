# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	fusefs
DISTVERSIONPREFIX=	fuse-
DISTVERSION=	2.9.9
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-libs

MAINTAINER=	se@FreeBSD.org
COMMENT=	FUSE allows filesystem implementation in userspace

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

IGNORE_DragonFly=	fusefs has not been implemented on DragonFly

PORTSCOUT=	limit:^2\.

USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
GH_PROJECT=	libfuse

USES=		autoreconf gettext-tools iconv libtool
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
PLIST_SUB=	VERSION=${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-configure:
	${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${STAGEDIR}${PREFIX}/include/fuse

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libs
	${INSTALL_DATA} ${WRKSRC}/doc/how-fuse-works ${WRKSRC}/doc/kernel.txt ${STAGEDIR}${DOCSDIR}/libs

.include <bsd.port.mk>
