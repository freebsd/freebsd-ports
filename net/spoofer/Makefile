# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	spoofer
PORTVERSION=	1.0.5
PORTREVISION=	1
CATEGORIES=	net
MASTER_SITES=	http://www.caida.org/projects/spoofer/downloads/

MAINTAINER=	mjl@luckie.org.nz
COMMENT=	Spoofer Project testing software

LICENSE=	GPLv3

BUILD_DEPENDS=	protoc:devel/protobuf
LIB_DEPENDS=	libprotobuf-lite.so:devel/protobuf

PORTDOCS=	README

USES=		compiler:c++11-lib
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=	--disable-development

OPTIONS_DEFINE=	DOCS GUI
OPTIONS_DEFAULT=	GUI
OPTIONS_SUB=	yes

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MGUI}
USE_QT5=	buildtools_build qmake_build core network gui widgets
USE_GL+=	gl
USE_RC_SUBR=	${PORTNAME}
INSTALLS_ICONS=	yes
.else
CONFIGURE_ARGS+=	--disable-manager
.endif

post-install:
.if ${PORT_OPTIONS:MGUI}
.for r in 16 32 48 64 128 256
	@${MKDIR} ${STAGEDIR}${PREFIX}/share/icons/hicolor/${r}x${r}/apps
	${INSTALL_DATA} ${WRKSRC}/icons/spoofer${r}.png \
		${STAGEDIR}${PREFIX}/share/icons/hicolor/${r}x${r}/apps/spoofer.png
.endfor
.endif

do-install-DOCS-on:
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for f in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${f} ${STAGEDIR}${DOCSDIR}
.endfor

.include <bsd.port.mk>
