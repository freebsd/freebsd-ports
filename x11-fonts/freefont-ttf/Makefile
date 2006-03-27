# Ports collection makefile for:	freefont-ttf
# Date created:				2005-12-17
# Whom:					Andreas Kohn <andreas@syndrom23.de>
#
# $FreeBSD$
#

PORTNAME=		freefont-ttf
PORTVERSION=		20060126
CATEGORIES=		x11-fonts
MASTER_SITES=		${MASTER_SITE_SAVANNAH}
MASTER_SITE_SUBDIR=	freefont

MAINTAINER=		andreas@syndrom23.de
COMMENT=		Free UCS Outline Fonts

NO_BUILD=		yes
USE_X_PREFIX=		yes
WRKSRC=			${WRKDIR}/freefont-${PORTVERSION}
SUB_FILES=		pkg-message
SUB_LIST=		INSTALLDIR=${INSTALLDIR}
PKGMESSAGE=		${WRKDIR}/pkg-message

INSTALLDIR=		${PREFIX}/lib/X11/fonts/${PORTNAME}

do-install:
.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/AUTHORS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/CREDITS ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/ChangeLog ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/COPYING ${DOCSDIR}
.endif
	${MKDIR} ${INSTALLDIR}
	${INSTALL_DATA} ${WRKSRC}/*.ttf ${INSTALLDIR}
	# Use these pregenerated files instead of using mkfontscale and mkfontdir
	# to avoid xorg-clients dependency
	${INSTALL_DATA} ${FILESDIR}/fonts.scale ${INSTALLDIR}
	${INSTALL_DATA} ${FILESDIR}/fonts.dir ${INSTALLDIR}

post-install:
	@${CAT} ${PKGMESSAGE}
.include <bsd.port.mk>
