# New ports collection makefile for:	sgifonts
# Date created:				2002-05-31
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	sgifonts
PORTVERSION=	1.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://patches-europe.sgi.com/pub/linux/ProPack1.4/SRPMS/ \
   ftp://ftp.rediris.es/sites/patches-europe.sgi.com/pub/linux/ProPack1.4/SRPMS/
DISTNAME=	sgi-fonts-1.0-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Fonts from the SGI ProPack 1.4 (originally for Linux)

EXTRACT_DEPENDS=	rpm2cpio.pl:${PORTSDIR}/archivers/rpm2cpio
BUILD_DEPENDS=	bdftopcf:${X_CLIENTS_PORT}

PLIST=		${WRKDIR}/pkg-plist
PLIST_DIRS=	lib/X11/fonts/local/sgi
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/sgi-fonts

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR}; rpm2cpio.pl ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
		| ${CPIO} --extract --no-preserve-owner \
		--preserve-modification-time --unconditional --quiet
	@${TAR} -C ${WRKDIR} -xf ${WRKDIR}/sgi-fonts.tar.gz

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
