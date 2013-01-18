# Created by: Emanuel Haupt <ehaupt@FreeBSD.org>
# $FreeBSD$

PORTNAME=	ext4fuse
PORTVERSION=	0.1.2
PORTEPOCH=	1
CATEGORIES=	sysutils
PKGNAMEPREFIX=	fusefs-

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	EXT4 implementation for FUSE

LICENSE=	GPLv2

LIB_DEPENDS=	execinfo:${PORTSDIR}/devel/libexecinfo

USE_FUSE=	yes
USE_GMAKE=	yes
USE_PKGCONFIG=	build
USE_GITHUB=	yes
GH_ACCOUNT=	gerard
GH_COMMIT=	6b28a2b
GH_TAGNAME=	v${PORTVERSION}

MAKE_JOBS_SAFE=	yes

# explicitly empty to fix a cross compiling related issue (PR: 165480)
MAKE_ENV+=	TARGET_ARCH=

ALL_TARGET=	${PORTNAME}

PLIST_FILES=	bin/ext4fuse

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin

.include <bsd.port.mk>
