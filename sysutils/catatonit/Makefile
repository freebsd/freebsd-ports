PORTNAME=	catatonit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.1.7
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	A signal-forwarding process manager for containers
WWW=		https://github.com/openSUSE/catatonit

LICENSE=	GPLv3

USES=		autoreconf gmake
USE_GITHUB=	yes
GH_ACCOUNT=	dfr
GH_TAGNAME=	65a1a0f

HAS_CONFIGURE=	yes

pre-configure:
	@(cd ${WRKSRC} && ./autogen.sh)

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/podman
	@${RLN} ${STAGEDIR}${PREFIX}/bin/catatonit ${STAGEDIR}${PREFIX}/libexec/podman/catatonit

.include <bsd.port.mk>
