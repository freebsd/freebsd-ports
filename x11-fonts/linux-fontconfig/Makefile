# New ports collection makefile for:	linux-fontconfig
# Date created:				2003-11-19
# Whom:					trevor
#
# $FreeBSD$
#

PORTNAME=	fontconfig
PORTVERSION=	2.2.3
PORTREVISION=	3
CATEGORIES=	x11-fonts linux
DISTNAME=	${PORTNAME}-${PORTVERSION}-5

MAINTAINER=	freebsd-emulation@FreeBSD.org
COMMENT=	Linux/i386 binary of Fontconfig

RUN_DEPENDS=	${LINUXBASE}/usr/lib/libexpat.so.0:${PORTSDIR}/textproc/linux-expat

USE_REINPLACE=	yes
ONLY_FOR_ARCHS=	i386 amd64
USE_LINUX_RPM=	yes
LINUX_DIST_VER=	3
INSTALLS_SHLIB=	yes

BRANDELF_DIRS=	usr/bin

post-patch:
	@${REINPLACE_CMD} -i ""  -e 's:/usr/share/fonts:${X11BASE}/lib/X11/fonts:g ; \
		s:/usr/X11R6/lib/X11/fonts/OTF:${X11BASE}/lib/X11/fonts/bitstream-vera:g' \
		${WRKSRC}/etc/fonts/fonts.conf

post-install:
	PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.mk>
