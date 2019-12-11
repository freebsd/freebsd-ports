# $FreeBSD$

PORTNAME=	twmn
PORTVERSION=	g20171216
PORTREVISION=	9
CATEGORIES=	sysutils

MAINTAINER=	dmgk@FreeBSD.org
COMMENT=	Notification system for tiling window managers

LICENSE=	LGPL3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libboost_system.so:devel/boost-libs

USES=		compiler:c++11-lang qmake qt:5
USE_GITHUB=	yes
GH_ACCOUNT=	sboli
GH_TAGNAME=	5b92ac5
USE_QT=		core dbus gui network widgets x11extras buildtools_build
LDFLAGS+=	-Wl,--as-needed  # see bug#224488

# Fix build with Qt 5.13
QMAKE_ARGS+=	DEFINES+=QT_NO_DEPRECATED_WARNINGS=Y

PORTDOCS=	README.md
PORTEXAMPLES=	*

PLIST_FILES=	bin/twmnc bin/twmnd

OPTIONS_DEFINE=	DOCS EXAMPLES

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/twmnc ${STAGEDIR}${PREFIX}/bin/twmnd

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${STAGEDIR}${DOCSDIR}

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	cd ${WRKSRC}/examples && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR}

.include <bsd.port.mk>
