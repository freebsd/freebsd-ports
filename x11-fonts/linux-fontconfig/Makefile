# New ports collection makefile for:	linux-fontconfig
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.2.3
PORTREVISION=	9
CATEGORIES=	x11-fonts linux
MASTER_SITES=	CRITICAL/rpm/${LINUX_RPM_ARCH}/fedora/${LINUX_DIST_VER}
DISTNAME=	${PORTNAME}-${PORTVERSION}-13

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	Linux/i386 binary of Fontconfig

CONFLICTS=	linux-f8-fontconfig-[0-9]* linux-f10-fontconfig-[0-9]*

ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
USE_LINUX_APPS=	expat
LINUX_DIST_VER=	4
USE_LDCONFIG=	yes
PLIST_SUB+=	PORTVERSION="${PORTVERSION}"

BRANDELF_DIRS=	usr/bin

# We will use some other configuration file, so delete a linux one
# Don't let the linux fc-cache mess up the native cache file
post-extract:
	@${RM} ${WRKSRC}/etc/fonts/fonts.conf \
		${WRKSRC}/usr/bin/fc-cache \
		${WRKSRC}/usr/share/man/man1/fc-cache.1.gz

# Here is our configuration file
post-patch:
	@${CAT} ${FILESDIR}/fonts.conf | ${SED} 's:/usr/X11R6:${LOCALBASE}:g' > ${WRKSRC}/etc/fonts/fonts.conf

.include <bsd.port.mk>
