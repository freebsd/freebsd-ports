PORTNAME=	onefetch
DISTVERSION=	2.18.1
PORTREVISION=	5
CATEGORIES=	sysutils devel

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Git repository summary on your terminal
WWW=		https://github.com/o2sh/onefetch

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE.md

LIB_DEPENDS=	libgit2.so:devel/libgit2
RUN_DEPENDS=	git:devel/git

USES=		cargo
USE_GITHUB=	yes
GH_ACCOUNT=	o2sh

PLIST_FILES=	bin/${PORTNAME}
PORTDOCS=	CONTRIBUTING.md README.md

OPTIONS_DEFINE=		DOCS MANPAGES
OPTIONS_DEFAULT=	MANPAGES

MANPAGES_PLIST_FILES=	man/man1/${PORTNAME}.1.gz

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-MANPAGES-on:
	${INSTALL_MAN} ${WRKSRC}/docs/${PORTNAME}.1 ${STAGEDIR}${MAN1PREFIX}/man/man1

.include <bsd.port.mk>
