PORTNAME=	qga-guest-exec
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.0
CATEGORIES=	sysutils

MAINTAINER=	dtxdf@FreeBSD.org
COMMENT=	Run commands in a guest via the QEMU Guest Agent protocol

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	jq:textproc/jq

USE_GITHUB=	yes
GH_ACCOUNT=	DtxdF

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/qga-guest-exec \
		share/man/man1/qga-guest-exec.1.gz

.include <bsd.port.mk>
