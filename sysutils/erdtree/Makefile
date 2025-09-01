PORTNAME=	erdtree
DISTVERSIONPREFIX=	v
DISTVERSION=	3.1.2
PORTREVISION=	19
CATEGORIES=	sysutils

MAINTAINER=	se@FreeBSD.org
COMMENT=	Filesystem and disk-usage analysis tool
WWW=		https://github.com/solidiquis/erdtree

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	solidiquis

TEST_TARGET=	tests

PLIST_FILES=	bin/erd

.include <bsd.port.mk>
