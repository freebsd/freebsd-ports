PORTNAME=	feluda
DISTVERSION=	1.8.5
CATEGORIES=	textproc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Detect license usage restrictions in your project
WWW=		https://github.com/anistark/feluda

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libgit2.so:devel/libgit2 \
		libssh2.so:security/libssh2

USES=		cargo localbase ssl
USE_GITHUB=	yes
GH_ACCOUNT=	anistark

PLIST_FILES=	bin/${PORTNAME}

.include <bsd.port.mk>
