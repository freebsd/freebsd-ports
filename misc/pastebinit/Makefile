PORTNAME=	pastebinit
PORTVERSION=	1.7.0
CATEGORIES=	misc python

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line utility for pastebin
WWW=		https://github.com/pastebinit/pastebinit

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		python:run shebangfix
USE_GITHUB=	yes
SHEBANG_FILES=	pastebinit
NO_BUILD=	yes
NO_ARCH=	yes

PLIST_FILES=	bin/pastebinit
PORTDATA=	*
PORTDOCS=	*

OPTIONS_DEFINE=	PASTEBINS DOCS
OPTIONS_DEFAULT=PASTEBINS
PASTEBINS_DESC=	Install default pastebins

post-patch:
	@${REINPLACE_CMD} -e 's|/usr/local/share|${DATADIR}|g' \
		-e 's|/usr/local|${LOCALBASE}|g' \
		${WRKSRC}/pastebinit

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-PASTEBINS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${STAGEDIR}${DATADIR}/

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}/
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}/

.include <bsd.port.mk>
