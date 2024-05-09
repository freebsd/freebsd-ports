PORTNAME=	vmstated
DISTVERSION=	0.10
CATEGORIES=	sysutils

MAINTAINER=	freebsd@ny-central.org
COMMENT=	Manages and runs bhyve virtual machines and infrastructure
WWW=		https://github.com/christian-moerz/vmstated

LICENSE=	BSD2CLAUSE

ONLY_FOR_ARCHS=	aarch64 amd64
NOT_FOR_ARCHS_REASON=	only available where bhyve is

USE_GITHUB=	yes
GH_ACCOUNT=	christian-moerz
GH_PROJECT=	vmstated

post-patch:
	${REINPLACE_CMD} "s@PREFIX@${PREFIX}@g" "${WRKSRC}/rc/vmstated"

.include <bsd.port.mk>
