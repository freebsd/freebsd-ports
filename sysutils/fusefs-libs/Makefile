# Created by: Anish Mistry
# $FreeBSD$

PORTNAME=	fusefs
DISTVERSIONPREFIX=	fuse_
DISTVERSION=	2_9_5
CATEGORIES=	sysutils
PKGNAMESUFFIX=	-libs

MAINTAINER=	brendan+freebsd@bbqsrc.net
COMMENT=	FUSE allows filesystem implementation in userspace

LICENSE=	LGPL21
LICENSE_FILE=	${WRKSRC}/COPYING.LIB

OPTIONS_DEFINE=	DOCS

USE_GITHUB=	yes
GH_ACCOUNT=	libfuse
GH_PROJECT=	libfuse

GNU_CONFIGURE=	yes
CONFIGURE_ENV=	MOUNT_FUSE_PATH=${PREFIX}/sbin
CONFIGURE_ARGS=	--prefix=${PREFIX} \
		--with-pkgconfigdir=${PREFIX}/libdata/pkgconfig
INSTALL_TARGET=	install-strip
USES=		iconv libtool autoreconf gettext-tools
USE_LDCONFIG=	yes

PORTDOCS=	*

pre-configure:
	${CP} ${LOCALBASE}/share/gettext/config.rpath ${WRKSRC}

post-install:
	${INSTALL_DATA} ${WRKSRC}/include/fuse_kernel.h ${STAGEDIR}${PREFIX}/include/fuse
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/libs
	${INSTALL_DATA} ${WRKSRC}/doc/how-fuse-works ${WRKSRC}/doc/kernel.txt ${STAGEDIR}${DOCSDIR}/libs

.include <bsd.port.pre.mk>

.if ${OPSYS} == DragonFly
IGNORE=	fusefs has not been implemented on DragonFly
.endif

.include <bsd.port.post.mk>
