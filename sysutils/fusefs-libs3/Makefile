PORTNAME=	fusefs-libs3
DISTVERSION=	3.11.0
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/libfuse/libfuse/releases/download/fuse-${DISTVERSION}/
DISTNAME=	fuse-${DISTVERSION}

MAINTAINER=	se@FreeBSD.org
COMMENT=	FUSE library version 3 for filesystems implemented in userspace

LICENSE=	GPLv2 LGPL21
LICENSE_COMB=	multi
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		compiler iconv meson tar:xz
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

.if ${CHOSEN_COMPILER_TYPE} == gcc
post-patch:
	${REINPLACE_CMD} -e '/-Wno-unused-result/d' ${WRKSRC}/meson.build
.endif

.include <bsd.port.post.mk>
