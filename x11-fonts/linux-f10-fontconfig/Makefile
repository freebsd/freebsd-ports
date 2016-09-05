# Created by: bsam
# $FreeBSD$

PORTNAME=	fontconfig
PORTVERSION=	2.6.0
PORTREVISION=	1
CATEGORIES=	x11-fonts linux

MAINTAINER=	emulation@FreeBSD.org
COMMENT=	XML-based font configuration API for X Windows (Linux Fedora 10)

CONFLICTS=	linux-fontconfig-[0-9]* linux-f8-fontconfig-[0-9]*

USES=		linux:f10
USE_LINUX_RPM=	yes
USE_LINUX=	expat

RPMVERSION=	3.fc10
USE_LDCONFIG=	yes

# We will use some other configuration file, so delete a linux one
# Don't let the linux fc-cache mess up the native cache file
post-extract:
		@${RM} -r ${WRKSRC}/etc ${WRKSRC}/usr/share/fonts ${WRKSRC}/var \
			${WRKSRC}/usr/bin/fc-cache \
			${WRKSRC}/usr/share/man/man1/fc-cache.1.gz

post-install:
		${MKDIR} ${STAGEDIR}${PREFIX}/etc
		@${LN} -s ${LOCALBASE}/etc/fonts ${STAGEDIR}${PREFIX}/etc/

DESCR=		${.CURDIR}/../${PORTNAME}/pkg-descr

.include <bsd.port.mk>
