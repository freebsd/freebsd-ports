PORTNAME=	fusefs
DISTVERSION=	2.9.9
PORTREVISION=	2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/libfuse/libfuse/releases/download/fuse-${DISTVERSION}/
PKGNAMESUFFIX=	-libs
DISTNAME=	fuse-${DISTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	FUSE allows filesystem implementation in userspace

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

IGNORE_DragonFly=	fusefs has not been implemented on DragonFly

USES=		autoreconf gettext-tools iconv libtool
USE_LDCONFIG=	yes

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
INSTALL_TARGET=	install-strip

PORTSCOUT=	limit:^2\.

PLIST_SUB=	VERSION=${PORTVERSION}
PORTDOCS=	*

OPTIONS_DEFINE=	DOCS

pre-configure:
	${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libs
	${INSTALL_DATA} ${WRKSRC}/doc/how-fuse-works ${WRKSRC}/doc/kernel.txt ${STAGEDIR}${DOCSDIR}/libs

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${STAGEDIR}${PREFIX}/include/fuse

.include <bsd.port.mk>
