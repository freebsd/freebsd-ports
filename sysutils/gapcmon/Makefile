# $FreeBSD$

PORTNAME=	gapcmon
PORTVERSION=	0.8.9
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Monitor apcupsd with GTK+2 GUI

LICENSE=	GPLv2

SUB_FILES=	pkg-message
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2
USES=		pkgconfig
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL README

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-extract:
	@${REINPLACE_CMD} 's|install-gapcmondocDATA \\|\\|' \
		${WRKSRC}/Makefile.in

post-install:
.if ${PORT_OPTIONS:MDOCS}
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
