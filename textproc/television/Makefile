PORTNAME=	television
DISTVERSION=	0.11.9
PORTREVISION=	2
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

PLIST_FILES=	bin/television \
		bin/tv

post-install:
	@(cd ${STAGEDIR}${PREFIX}/bin && \
		${LN} tv television)

.include <bsd.port.mk>
