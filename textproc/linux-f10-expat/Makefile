# New ports collection makefile for:	linux-expat
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.5
PORTREVISION=	0
CATEGORIES=	textproc linux

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Linux/i386 binary port of Expat XML-parsing library

BASEVERSION=	9
ONLY_FOR_ARCHS=	i386
PLIST=		${WRKDIR}/plist
RPM_SET=	expat-1.95.5-2.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | cpio -div; \
		${FIND} * -type f -o -type l > ${PLIST}
	${ECHO_CMD} @dirrm usr/share/doc/expat-1.95.5 >> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
