# New ports collection makefile for:	linux-urw-fonts
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=		urw-fonts
PORTVERSION=		2.0
PORTREVISION=		0
CATEGORIES=		x11-fonts linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Truetype fonts for use with Linux programs

BASEVERSION=	9
MD5_FILE=	${MASTERDIR}/distinfo
PLIST=		${WRKDIR}/plist
RPM_SET=	urw-fonts-2.0-29.noarch.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -id; \
		${FIND} * -type f -o -type l > ${PLIST}; \
		${FIND} -d * -type d | ${GREP} -E 'urw|default' | \
		${SED} -e 's:^:@dirrm :' >> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
