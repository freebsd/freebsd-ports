# New ports collection makefile for:	sgifonts
# Date created:				2002-05-31
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	sgifonts
PORTVERSION=	1.0.1
CATEGORIES=	x11-fonts
MASTER_SITES=	ftp://oss.sgi.com/projects/sgilinux-combined/download/sgipropack1.4/MNT-INSTALL/SGI/SRPMS/
DISTNAME=	sgi-fonts-1.0-1.src
EXTRACT_SUFX=	.rpm

MAINTAINER=	trevor@FreeBSD.org

BUILD_DEPENDS=	rpm2cpio:${PORTSDIR}/archivers/rpm2cpio \
		bdftopcf:${PORTSDIR}/x11/XFree86-4-clients

PLIST=		${WRKDIR}/pkg-plist
PKGMESSAGE=	${WRKDIR}/pkg-message
USE_IMAKE=	yes
WRKSRC=		${WRKDIR}/sgi-fonts

do-extract:
	@${MKDIR} ${WRKDIR}
	@cd ${WRKDIR}; rpm2cpio ${DISTDIR}/${DIST_SUBDIR}/${DISTFILES} \
		| cpio --extract --no-preserve-owner \
		--preserve-modification-time --unconditional --quiet
	@${TAR} -C ${WRKDIR} -xf ${WRKDIR}/sgi-fonts.tar.gz

pre-install:
	@${RM} -f ${PLIST}
	@cd ${WRKSRC}; for ii in `${LS} *gz fonts.alias fonts.dir | sort`; do \
		${ECHO_CMD} lib/X11/fonts/local/sgi/$${ii} >> ${PLIST}; \
	done
	@${ECHO_CMD} @dirrm lib/X11/fonts/local/sgi >> ${PLIST}
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
