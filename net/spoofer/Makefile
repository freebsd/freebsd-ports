# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spoofer
PORTVERSION=	1.4.5
PORTREVISION=	5
CATEGORIES=	net
MASTER_SITES=	https://www.caida.org/projects/spoofer/downloads/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Spoofer Project testing software

LICENSE=	GPLv3

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libprotobuf-lite.so:devel/protobuf
RUN_DEPENDS=	scamper:net/scamper

USES=		compiler:c++11-lib

CONFIGURE_ARGS=	--disable-development --with-protobuf=${LOCALBASE}
GNU_CONFIGURE=	yes

PORTDOCS=	README

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_DEFAULT=GUI
OPTIONS_SUB=	yes

GUI_CONFIGURE_ENABLE=	manager
GUI_USE=	GL=gl QT=buildtools_build,qmake_build,core,network,gui,widgets
GUI_USES=	gl qt:5
GUI_VARS=	USE_RC_SUBR=${PORTNAME}

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/${PORTDOCS} ${STAGEDIR}${DOCSDIR}

do-install-GUI-on:
.for r in 16 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${r}x${r}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/spoofer${r}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${r}x${r}/apps/spoofer.png
.endfor

.include <bsd.port.mk>
