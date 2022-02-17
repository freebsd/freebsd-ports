PORTNAME=	scli
DISTVERSIONPREFIX=	v
DISTVERSION=	0.7.0
CATEGORIES=	net-im python

MAINTAINER=	0mp@FreeBSD.org
COMMENT=	Simple terminal user interface for the Signal messenger (using signal-cli)

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}urwid-readline>=0:devel/py-urwid-readline@${PY_FLAVOR} \
		${PYTHON_PKGNAMEPREFIX}urwid>=0:devel/py-urwid@${PY_FLAVOR} \
		dbus>=0:devel/dbus \
		signal-cli>=0.8.4.1:net-im/signal-cli

USES=		python:run,3.7+ shebangfix
USE_GITHUB=	yes
GH_ACCOUNT=	isamert
SHEBANG_FILES=	${PORTNAME}

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/${PORTNAME} \
		share/${PORTNAME}/${PORTNAME} \
		share/${PORTNAME}/VERSION

SUB_FILES=	scli

PORTDOCS=	README.md screenshots/1.png screenshots/2.png screenshots/3.png

OPTIONS_DEFINE=		DOCS LINKING
OPTIONS_DEFAULT=	LINKING

LINKING_DESC=		Linking support for the --link flag
LINKING_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}pyqrcode>=0:graphics/py-pyqrcode@${PY_FLAVOR}

post-patch:
	${REINPLACE_CMD} 's|%%DOCSDIR%%|${DOCSDIR}|g' ${WRKSRC}/${PORTNAME}

do-install:
	@${MKDIR} ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME} ${STAGEDIR}${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/VERSION ${STAGEDIR}${DATADIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} ${STAGEDIR}${PREFIX}/bin

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README.md ${STAGEDIR}${DOCSDIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} screenshots ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
