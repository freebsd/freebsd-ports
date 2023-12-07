PORTNAME=	postforward
DISTVERSIONPREFIX=	v
DISTVERSION=	1.1.1
PORTREVISION=	10
CATEGORIES=	mail

MAINTAINER=	luca@asgard.ch
COMMENT=	Postfix SRS forwarding agent
WWW=		https://github.com/zoni/postforward

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

DEPRECATED=	Obsolete as postsrsd 2.x uses unix sockets instead of tcp
EXPIRATION_DATE=2023-12-31

RUN_DEPENDS=	postsrsd:mail/postsrsd

USES=		go

USE_GITHUB=	yes
GH_ACCOUNT=	zoni

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_BUILDFLAGS=	-ldflags="-s -w"

PLIST_FILES=	bin/${PORTNAME}

PORTDOCS=	README.md CHANGES.md

OPTIONS_DEFINE=	DOCS

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
