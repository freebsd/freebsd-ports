PORTNAME=	passh
DISTVERSIONPREFIX=	v
DISTVERSION=	1.0.1
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Non-interactive password inputting CLI

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	clarkwang

PLIST_FILES=	bin/passh
PORTDOCS=	README.md sshpass-broken.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
