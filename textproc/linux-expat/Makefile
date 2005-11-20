# New ports collection makefile for:	linux-expat
# Date created:				2003-07-05
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	expat
PORTVERSION=	1.95.7
PORTREVISION=	0
CATEGORIES=	textproc linux
MASTER_SITES=	${MASTER_SITE_FEDORA_LINUX}
MASTER_SITE_SUBDIR=	3/i386/os/Fedora/RPMS

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux/i386 binary port of Expat XML-parsing library

RUN_DEPENDS=

USE_LINUX=	yes
ONLY_FOR_ARCHS=	i386 amd64
PLIST=		${WRKDIR}/plist
RPM_SET=	expat-${PORTVERSION}-4.i386.rpm

pre-install:
	${RM} -rf ${WRKSRC}/tmp
	${MKDIR} ${WRKSRC}/tmp
	cd ${WRKSRC}/tmp; \
		rpm2cpio < ${DISTDIR}/${DIST_SUBDIR}/${RPM_SET} | ${CPIO} -div; \
		${FIND} * -type f -o -type l > ${PLIST}
	${ECHO_CMD} @dirrm usr/share/doc/expat-${PORTVERSION} >> ${PLIST}

.include "../../x11-toolkits/linux-gtk/Makefile"
