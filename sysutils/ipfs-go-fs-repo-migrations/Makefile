PORTNAME=	ipfs-go-fs-repo-migrations
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
PORTREVISION=	27
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ipfs/fs-repo-migrations/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Migrations for the filesystem repository of ipfs clients
WWW=		https://github.com/ipfs/fs-repo-migrations

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_aarch64=	fails to build: sys/unix/cap_freebsd.go:18:23: undefined: CAP_RIGHTS_VERSION_00

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		go:modules

WRKSRC=		${WRKDIR}/fs-repo-migrations-${DISTVERSION}
PLIST_FILES=	bin/fs-repo-migrations
GO_TARGET=	:fs-repo-migrations

.include <bsd.port.mk>
