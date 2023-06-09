PORTNAME=	rustypaste-cli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.4.0
PORTREVISION=	1
CATEGORIES=	www

MAINTAINER=	DtxdF@disroot.org
COMMENT=	CLI tool for rustypaste
WWW=		https://github.com/orhun/rustypaste-cli/

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	orhun

PLIST_DIRS=	${EXAMPLESDIR}
PLIST_FILES=	${EXAMPLESDIR}/config.toml \
		bin/rpaste

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/config.toml ${STAGEDIR}${EXAMPLESDIR}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/rpaste

.include <bsd.port.mk>
