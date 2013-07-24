# Created by: Gea-Suan Lin <gslin@gslin.org>
# $FreeBSD$

PORTNAME=	unionfs
PORTVERSION=	0.26
CATEGORIES=	sysutils
MASTER_SITES=	http://podgorny.cz/unionfs-fuse/releases/
PKGNAMEPREFIX=	fusefs-
DISTNAME=	unionfs-fuse-${PORTVERSION}

MAINTAINER=	clsung@FreeBSD.org
COMMENT=	FUSE based implementation of the well-known unionfs

PLIST_FILES=	bin/unionfs
MAN8+=		unionfs-fuse.8

USES=		fuse cmake
USE_XZ=		yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

post-patch:
	@${REINPLACE_CMD} "s,share/man,man,g" ${WRKSRC}/man/CMakeLists.txt

.include <bsd.port.mk>
