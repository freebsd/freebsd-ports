# New ports collection makefile for:	x11-fonts/linux-f10-fontconfig
# Date created:				2009-05-01
# Whom:					bsam
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.6.0
CATEGORIES=	x11-fonts linux
PKGNAMEPREFIX=	linux-f10-
DISTNAME=	${PORTNAME}-${PORTVERSION}-${RPMVERSION}

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	An XML-based font configuration API for X Windows (Linux Fedora 10)

CONFLICTS=	linux-fontconfig-[0-9]* linux-f8-fontconfig-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	expat
LINUX_DIST_VER=	10
RPMVERSION=	3.fc10
BRANDELF_DIRS=	usr/bin
USE_LDCONFIG=	yes

# We will use some other configuration file, so delete a linux one
# Don't let the linux fc-cache mess up the native cache file
post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/share/fonts ${WRKSRC}/var \
			${WRKSRC}/usr/bin/fc-cache \
			${WRKSRC}/usr/share/man/man1/fc-cache.1.gz

post-install:
		@${LN} -s ${LOCALBASE}/etc/fonts ${PREFIX}/etc/

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
