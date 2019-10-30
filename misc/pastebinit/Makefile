# $FreeBSD$

PORTNAME=	pastebinit
PORTVERSION=	1.5.1
CATEGORIES=	misc python
MASTER_SITES=	https://mirror.amdmi3.ru/distfiles/

MAINTAINER=	amdmi3@FreeBSD.org
COMMENT=	Command line utility for pastebin

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}configobj>=4.3.2:devel/py-configobj@${PY_FLAVOR}

USES=		python:3.6+,run shebangfix
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
	@${REINPLACE_CMD} -e 's|/usr/share/pastebin.d|${DATADIR}/pastebin.d|' \
		${WRKSRC}/pastebinit
do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin/${PORTNAME}

do-install-PASTEBINS-on:
	@cd ${WRKSRC} && ${COPYTREE_SHARE} pastebin.d ${STAGEDIR}${DATADIR}

do-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${STAGEDIR}${DOCSDIR}

.include <bsd.port.mk>
