# New ports collection makefile for:	linux-fontconfig
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.1
PORTREVISION=	1
CATEGORIES=	x11-fonts linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Linux/i386 binary of Fontconfig

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RPM_SET=	fontconfig-2.1-9.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${GREP} font | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
