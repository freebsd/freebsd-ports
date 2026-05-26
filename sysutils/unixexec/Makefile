PORTNAME=	unixexec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.5.1
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Attach stdin/stdout of a command to a Unix socket

LICENSE=	ISCL
LICENSE_FILE=	${WRKSRC}/LICENSE

TEST_DEPENDS=	bats:devel/bats-core

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

TEST_TARGET=	test

PLIST_FILES=	bin/unixexec

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/unixexec ${STAGEDIR}${PREFIX}/bin/unixexec

.include <bsd.port.mk>
