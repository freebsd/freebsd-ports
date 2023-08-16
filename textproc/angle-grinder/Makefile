PORTNAME=	angle-grinder
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.2
PORTREVISION=	1
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Slice and dice logs on the command line
WWW=		https://github.com/rcoh/angle-grinder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

BROKEN_FreeBSD_14=	fails to compile: failed to run custom build command for tikv-jemalloc-sys v0.5.3+5.3.0-patched

USES=		cargo ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rcoh

PLIST_FILES=	bin/agrind
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/agrind

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
