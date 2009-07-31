# New ports collection makefile for:	gapcmon
# Date Created:				Sun, May 28, 2006
# Whom:					Jason E. Hale <bsdkaffee@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	gapcmon
PORTVERSION=	0.8.9
PORTREVISION=	1
CATEGORIES=	sysutils
MASTER_SITES=	SFE

MAINTAINER=	bsdkaffee@gmail.com
COMMENT=	Monitor apcupsd with GTK+2 GUI

SUB_FILES=	pkg-message
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_GNOME=	gconf2
GNU_CONFIGURE=	yes

PORTDOCS=	AUTHORS ChangeLog INSTALL README

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 601103
IGNORE=		needs gethostbyname_r(3)
.endif

post-extract:
	@${REINPLACE_CMD} 's|install-gapcmondocDATA \\|\\|' \
		${WRKSRC}/Makefile.in

post-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${PORTDOCS:S|^|${WRKSRC}/|} ${DOCSDIR}
.endif
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
