# New ports collection makefile for: netscape-linux-6
# Version required:		6
# Date created:			8 April 2000
# Whom:				sada@FreeBSD.org
#
# $FreeBSD$
#

PORTNAME=	linux-netscape
PORTVERSION=	6
CATEGORIES=	www linux
MASTER_SITES=	ftp://ftp.netscape.com/pub/netscape6/english/6_PR1/unix/linux22/
DISTFILES=	netscape-v600pr1.x86-unknown-linux2.2.tar.gz

MAINTAINER=	ports@FreeBSD.org

RUN_DEPENDS=	${LINUX_BASE}/lib/ld.so:${PORTSDIR}/emulators/linux_base \
		${LINUX_BASE}/usr/lib/libgdk-1.2.so.0.5.0:${PORTSDIR}/x11-toolkits/linux-gtk \
		${LINUX_BASE}/usr/lib/libjpeg.so.62.0.0:${PORTSDIR}/graphics/linux-jpeg

LINUX_BASE=	/compat/linux
NO_BUILD=	yes
NO_FILTER_SHLIBS=	yes
ONLY_FOR_ARCHS=	i386
PLIST_SUB=	STARTUP_CMD=${STARTUP_CMD}
STRIP=
USE_XLIB=	yes
WRKSRC=	${WRKDIR}/package

INSTALL_DIR=	${PREFIX}/lib/linux-netscape6
STARTUP_CMD=	netscape6

post-configure:
	${SED} -e "s;%%INSTALL_DIR%%;${INSTALL_DIR};g" \
	${FILESDIR}/start.sh >${WRKDIR}/${STARTUP_CMD}

do-install:
	${MKDIR} ${INSTALL_DIR}
	${CP} -Rp ${WRKSRC}/* ${INSTALL_DIR}
	${INSTALL_SCRIPT} ${WRKDIR}/${STARTUP_CMD} ${PREFIX}/bin

.include <bsd.port.mk>
