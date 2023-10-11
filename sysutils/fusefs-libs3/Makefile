PORTNAME=	fusefs-libs3
DISTVERSION=	3.16.2
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/libfuse/libfuse/releases/download/fuse-${DISTVERSION}/
DISTNAME=	fuse-${DISTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	FUSE library version 3 for filesystems implemented in userspace
WWW=		https://github.com/libfuse/libfuse/wiki/Filesystems

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler iconv meson ninja
USE_LDCONFIG=	yes

LDFLAGS+=	-L${LOCALBASE}/lib ${ICONV_LIB}

PLIST_SUB=	VERSION=${PORTVERSION}

.include <bsd.port.pre.mk>

.if ${OPSYS} == "FreeBSD" && ${OSVERSION} < 1400014
EXTRA_PATCHES=	${FILESDIR}/extra-patch-test_meson.build
.endif
.if ${OPSYS} == DragonFly
IGNORE=	fusefs has not been implemented on DragonFly
.endif

.include <bsd.port.post.mk>
