# New ports collection makefile for:	linux-fontconfig
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.1
PORTREVISION=	3
CATEGORIES=	x11-fonts linux

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux/i386 binary of Fontconfig

EXTRACT_DEPENDS=rpm2cpio:${PORTSDIR}/archivers/rpm
BUILD_DEPENDS=	${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat
RUN_DEPENDS=	${BUILD_DEPENDS}

USE_REINPLACE=	yes
BASEVERSION=	9
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${WRKDIR}/plist
RPM_SET=	fontconfig-2.1-9.i386.rpm

#PKGINSTALL=	${WRKDIR}/pkg-install

do-extract:
	@${RM} -rf ${WRKSRC}/tmp
	@${MKDIR} ${WRKSRC}/tmp
	@cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id;

post-patch:
	@${REINPLACE_CMD} -i ""  -e 's:/usr/share/fonts:${X11BASE}/lib/X11/fonts:g ; \
		s:/usr/X11R6/lib/X11/fonts/OTF:${X11BASE}/lib/X11/fonts/bitstream-vera:g' \
		${WRKSRC}/tmp/etc/fonts/fonts.conf

pre-install:
	@cd ${WRKSRC}/tmp; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${GREP} font | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}

post-install:
	@${INSTALL_DATA} ${WRKSRC}/tmp/etc/fonts/fonts.conf ${PREFIX}/etc/fonts/
	@${BRANDELF} -t Linux ${PREFIX}/usr/bin/fc-cache ${PREFIX}/usr/bin/fc-list
#	@${SED} -e 's|%%PREFIX%%|${PREFIX}|g' < ${FILESDIR}/pkg-install.in \
#		> ${PKGINSTALL}
#.if !defined(PACKAGE_BUILDING)
#	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
#.endif

.include "../../x11-toolkits/linux-gtk/Makefile"
