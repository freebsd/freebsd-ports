# Created by: Artyom Mirgorodskiy <artyom.mirgorodsky@gmail.com>
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.8.0
PORTREVISION=	2
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Linux CentOS ${LINUX_DIST_VER})

CONFLICTS=	linux-fontconfig-[0-9]* linux-f8-fontconfig-[0-9]* linux-f10-fontconfig-[0-9]*

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr
RPMVERSION=	5.el6
USES=		linux:c6
USE_LDCONFIG=	yes
USE_LINUX=	expat
USE_LINUX_RPM=	yes

# We will use some other configuration file, so delete a linux one
# Don't let the linux fc-cache mess up the native cache file
post-patch:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/share/fonts ${WRKSRC}/var \
			${WRKSRC}/usr/bin/fc-cache \
			${WRKSRC}/usr/share/man/man1/fc-cache.1.gz

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc
		@${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/

.include <bsd.port.mk>
