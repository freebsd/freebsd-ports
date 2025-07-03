PORTNAME=	choose
DISTVERSIONPREFIX=	v
DISTVERSION=	1.3.6
PORTREVISION=	7
CATEGORIES=	textproc

MAINTAINER=	tagattie@FreeBSD.org
COMMENT=	Human-friendly and fast alternative to cut and (sometimes) awk
WWW=		https://github.com/theryangeary/choose

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo

USE_GITHUB=	yes
GH_ACCOUNT=	theryangeary

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	contributing.md readme.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_MAN} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
