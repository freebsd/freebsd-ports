PORTNAME=	television
DISTVERSION=	0.10.6
CATEGORIES=	textproc

MAINTAINER=	nxjoseph@protonmail.com
COMMENT=	Fast and extensible general purpose fuzzy finder TUI
WWW=		https://github.com/alexpasmantier/television

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libonig.so:devel/oniguruma

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	alexpasmantier

PLIST_FILES=	bin/tv

.include <bsd.port.mk>
