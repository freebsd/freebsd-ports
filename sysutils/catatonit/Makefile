PORTNAME=	catatonit
DISTVERSIONPREFIX=	v
DISTVERSION=	0.2.1
CATEGORIES=	sysutils

MAINTAINER=	dfr@FreeBSD.org
COMMENT=	Signal-forwarding process manager for containers
WWW=		https://github.com/openSUSE/catatonit

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		autoreconf libtool
USE_GITHUB=	yes
GH_ACCOUNT=	openSUSE

GNU_CONFIGURE=	yes

PLIST_FILES=	bin/catatonit \
		libexec/podman/catatonit

post-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/libexec/podman
	@${RLN} ${STAGEDIR}${PREFIX}/bin/catatonit ${STAGEDIR}${PREFIX}/libexec/podman/catatonit

.include <bsd.port.mk>
