PORTNAME=	catatonit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.7
PORTREVISION=	2
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	A signal-forwarding process manager for containers
WWW=		https://github.com/openSUSE/catatonit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	dfr
GH_TAGNAME=	74113d7

GNU_CONFIGURE=	yes

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/podman
	@${RLN} ${STAGEDIR}${PREFIX}/bin/catatonit ${STAGEDIR}${PREFIX}/libexec/podman/catatonit

.include <bsd.port.mk>
