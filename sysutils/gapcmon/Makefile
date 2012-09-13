# New ports collection makefile for:	gapcmon
# Date Created:				Sun, May 28, 2006
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gapcmon
PORTVERSION=	0.8.9
PORTREVISION=	4
CATEGORIES=	sysutils
MASTER_SITES=	SF

MAINTAINER=	jhale@FreeBSD.org
COMMENT=	Monitor apcupsd with GTK+2 GUI

SUB_FILES=	pkg-message
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL README

post-extract:
	@${REINPLACE_CMD} 's|install-gapcmondocDATA \\|\\|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
