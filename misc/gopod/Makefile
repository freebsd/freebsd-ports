# New ports collection makefile for:   gopod
# Date created:		4 April 2005
# Whom:			Emanuel Haupt <ehaupt@critical.ch>
#
# $FreeBSD$
#

PORTNAME=	gopod
PORTVERSION=	1.1
CATEGORIES=	misc
MASTER_SITES=	http://gopod.free-go.net/
DISTNAME=	goPod-${PORTVERSION}_linux_bsd

MAINTAINER=	ehaupt@critical.ch
COMMENT=	Utility to cap/uncap an iPod

GNU_CONFIGURE=	yes
USE_GMAKE=	yes
RESTRICTED=	Unclear legal status in EU countries
NO_PACKAGE=	Unclear legal status in EU countries

PATCH_WRKSRC=	${WRKDIR}/${DISTNAME}/gtk-version

PLIST_FILES=	bin/gopod

.if defined(WITH_GUI)
USE_X_PREFIX=	yes
USE_GNOME=	gtk20
WRKSRC=		${WRKDIR}/${DISTNAME}/gtk-version
PLIST_FILES+=	share/${PORTNAME}/capped.png \
		share/${PORTNAME}/go.png \
		share/${PORTNAME}/go_.png \
		share/${PORTNAME}/mask.xpm \
		share/${PORTNAME}/notdetected.png \
		share/${PORTNAME}/uncapped.png
PLIST_DIRS+=	share/${PORTNAME}
.else
WRKSRC=		${WRKDIR}/${DISTNAME}/console-version
.endif

pre-everything::
.if !defined(WITH_GUI)
	@${ECHO_MSG}
	@${ECHO_MSG} "You may define WITH_GUI if you want the gui version"
	@${ECHO_MSG}
.endif

post-patch:
	@${SED} -e "s|%%PREFIX%%|${PREFIX}|g" \
	${WRKSRC}/main.c > ${WRKSRC}/main.c.freebsd
	${MV} ${WRKSRC}/main.c.freebsd ${WRKSRC}/main.c

do-install:
.if defined(WITH_GUI)
	@${MKDIR} ${PREFIX}/share/${PORTNAME}
.for file in capped.png go.png go_.png mask.xpm notdetected.png uncapped.png
	${INSTALL_DATA} -m 0644 ${WRKSRC}/gfx/${file} ${PREFIX}/share/${PORTNAME}/${file}
.endfor
	${INSTALL_PROGRAM} -m 0110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.else
	${INSTALL_PROGRAM} -m 0110 ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
.endif

.if !defined(NOPORTDOCS)
	${MKDIR} ${DOCSDIR}
	${INSTALL_DATA} ${WRKSRC}/README_EN ${WRKSRC}/README_FR ${DOCSDIR}
PLIST_FILES+=	share/doc/${PORTNAME}/README_EN \
		share/doc/${PORTNAME}/README_FR
PLIST_DIRS+=	share/doc/${PORTNAME}
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
