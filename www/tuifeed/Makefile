PORTNAME=	tuifeed
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.2
PORTREVISION=	3
CATEGORIES=	www

MAINTAINER=	driesm@FreeBSD.org
COMMENT=	Terminal feed reader with a fancy UI
WWW=		https://github.com/veeso/tuifeed

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	veeso

CARGO_BUILD_ARGS=	--locked
CARGO_INSTALL_ARGS=	--locked
CARGO_UPDATE_ARGS=	--locked

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	*md
OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
