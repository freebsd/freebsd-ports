PORTNAME=	ipfs-go-fs-repo-migrations
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
PORTREVISION=	33
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ipfs/fs-repo-migrations/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Migrations for the filesystem repository of ipfs clients
WWW=		https://github.com/ipfs/fs-repo-migrations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

DEPRECATED=	Obsolete port, no longer required for migrations
EXPIRATION_DATE=	2025-12-31
BROKEN_aarch64=	fails to build: sys/unix/cap_freebsd.go:18:23: undefined: CAP_RIGHTS_VERSION_00
ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		go:modules

GO_TARGET=	:fs-repo-migrations

WRKSRC=		${WRKDIR}/fs-repo-migrations-${DISTVERSION}

PLIST_FILES=	bin/fs-repo-migrations

.include <bsd.port.mk>
