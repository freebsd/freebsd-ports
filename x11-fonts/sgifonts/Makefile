# Created by: trevor
# $FreeBSD$

PORTNAME=	sgifonts
PORTVERSION=	1.0.1
PORTREVISION=	2
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://patches-europe.sgi.com/pub/linux/ProPack1.4/SRPMS/ \
		ftp://ftp.rediris.es/sites/patches-europe.sgi.com/pub/linux/ProPack1.4/SRPMS/
DISTNAME=	sgi-fonts-1.0-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Fonts from the SGI ProPack 1.4 (originally for Linux)

BUILD_DEPENDS=		bdftopcf:${PORTSDIR}/x11-fonts/bdftopcf \
			mkfontdir:${PORTSDIR}/x11-fonts/mkfontdir

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	lib/X11/fonts/local/sgi
PKGMESSAGE=	${WRKDIR}/pkg-message
USES=		imake
EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-O -xf
EXTRACT_AFTER_ARGS=	sgi-fonts.tar.gz | ${TAR} -xf -
WRKSRC=		${WRKDIR}/sgi-fonts

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}; for ii in `${LS} *gz fonts.alias fonts.dir|${SORT}`; do \
		${ECHO_CMD} lib/X11/fonts/local/sgi/$${ii} >> ${PLIST}; \
	done
	@${ECHO_CMD} "******************************************" >${PKGMESSAGE}
	@${ECHO_CMD} "Add a line" >> ${PKGMESSAGE}
	@${ECHO_CMD} "FontPath \"${PREFIX}/lib/X11/fonts/local/sgi\"" \
		>> ${PKGMESSAGE}
	@${ECHO_CMD} \
	"to your XF86Config." >> ${PKGMESSAGE}
	@${ECHO_CMD} "Then, restart the X server or do \"xset fp rehash\"."\
		>> ${PKGMESSAGE}
	@${ECHO_CMD} "*****************************************" >>${PKGMESSAGE}

do-install:
	${MKDIR} ${PREFIX}/lib/X11/fonts/local/sgi
	cd ${WRKSRC}; \
		${INSTALL_DATA} *gz fonts.alias fonts.dir \
		${PREFIX}/lib/X11/fonts/local/sgi
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
