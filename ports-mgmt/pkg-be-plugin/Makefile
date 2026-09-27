PORTNAME=	pkg-be-plugin
DISTVERSION=	1.0.1
CATEGORIES=	ports-mgmt sysutils

MAINTAINER=	sasha@starnix.net
COMMENT=	Plugin for pkg(8) to auto-create ZFS boot environments
WWW=		https://github.com/usenix17/pkg-be-plugin

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libpkg.so:ports-mgmt/pkg

USES=		uidfix
USE_GITHUB=	yes
GH_ACCOUNT=	usenix17

NO_TEST=	yes
SUB_FILES=	pkg-message

PLIST_FILES=	lib/pkg/be.so \
		"@sample etc/pkg/be.conf.sample" \
		share/man/man8/pkg-be-plugin.8.gz
PORTDOCS=	README.md RELEASE-NOTES.md

OPTIONS_DEFINE=	DOCS

post-patch:
	${REINPLACE_CMD} -e 's#/usr/local#${PREFIX}#' ${WRKSRC}/pkg-be-plugin.8

pre-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/lib/pkg
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/pkg
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/man/man8

post-install:
	${INSTALL_DATA} ${WRKSRC}/be.conf \
		${STAGEDIR}${PREFIX}/etc/pkg/be.conf.sample
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/pkg/be.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/RELEASE-NOTES.md ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
