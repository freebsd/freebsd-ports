# $FreeBSD$

PORTNAME=	ipfs-go-fs-repo-migrations
DISTVERSIONPREFIX=	v
DISTVERSION=	1.7.1
CATEGORIES=	sysutils
MASTER_SITES=	https://github.com/ipfs/fs-repo-migrations/archive/${DISTVERSIONFULL}${EXTRACT_SUFX}?dummy=/

MAINTAINER=	swills@FreeBSD.org
COMMENT=	Migrations for the filesystem repository of ipfs clients

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

ONLY_FOR_ARCHS=	aarch64 amd64 i386

USES=		go:modules

WRKSRC=		${WRKDIR}/fs-repo-migrations-${DISTVERSION}
PLIST_FILES=	bin/fs-repo-migrations
GO_TARGET=	:fs-repo-migrations

.include <bsd.port.mk>
