PORTNAME=	amdmsrtweaker
PORTVERSION=	1.1
CATEGORIES=	sysutils

MAINTAINER=	danfe@FreeBSD.org
COMMENT=	Tool to reprogram the P-states on various AMD CPUs and APUs

LICENSE=	GPLv3

ONLY_FOR_ARCHS=	i386 amd64

USE_GITHUB=	yes
GH_PROJECT=	${PORTNAME}-lnx
GH_ACCOUNT=	danfe
GH_TAGNAME=	6139b13

CXXFLAGS+=	-Wall -Werror -pedantic

PLIST_FILES=	sbin/amdmsrt
PORTDOCS=	readme.txt

OPTIONS_DEFINE=	DOCS

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/amdmsrt ${STAGEDIR}${PREFIX}/sbin

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/readme.txt ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
