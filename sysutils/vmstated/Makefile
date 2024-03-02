PORTNAME=	vmstated
DISTVERSION=	0.04
PORTREVISION=	1
CATEGORIES=	sysutils

MAINTAINER=	freebsd@ny-central.org
COMMENT=	Manages and runs bhyve virtual machines and infrastructure
WWW=		https://github.com/christian-moerz/vmstated

LICENSE=	BSD2CLAUSE

USE_GITHUB=	yes
GH_ACCOUNT=	christian-moerz
GH_PROJECT=	vmstated

post-patch:
	${REINPLACE_CMD} "s@PREFIX@${PREFIX}@g" "${WRKSRC}/rc/vmstated"
	# Fix man path
	${REINPLACE_CMD} \
		'20 s|$${MANPREFIX}|$${PREFIX}/share|' \
		"${WRKSRC}/src/vmstatedctl/Makefile"

.include <bsd.port.mk>
