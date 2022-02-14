# Created by: Mateusz Piotrowski <0mp@FreeBSD.org>

PORTNAME=	passh
PORTVERSION=	g20210412
CATEGORIES=	security

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Non-interactive password inputting CLI

LICENSE=	GPLv3+
LICENSE_FILE=	${WRKSRC}/LICENSE

USE_GITHUB=	yes
GH_ACCOUNT=	clarkwang
GH_TAGNAME=	a7506523edcbfc04e6c7481864ec7b086b71741f

PLIST_FILES=	bin/passh
PORTDOCS=	README.md sshpass-broken.md

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
