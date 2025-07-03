PORTNAME=	angle-grinder
DISTVERSIONPREFIX=	v
DISTVERSION=	0.19.4
PORTREVISION=	10
CATEGORIES=	textproc

MAINTAINER=	lcook@FreeBSD.org
COMMENT=	Slice and dice logs on the command line
WWW=		https://github.com/rcoh/angle-grinder

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		cargo gmake ssl
USE_GITHUB=	yes
GH_ACCOUNT=	rcoh

PLIST_FILES=	bin/agrind
PORTDOCS=	README.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
