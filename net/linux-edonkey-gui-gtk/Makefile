# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2.0.a
CATEGORIES=	net linux
MASTER_SITES=	http://users.aber.ac.uk/tpm01/
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	linux_gui_alpha_unstable
EXTRACT_SUFX=

MAINTAINER=	lioux@FreeBSD.org

RUN_DEPENDS=	donkey:${PORTSDIR}/net/edonkey-core \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

ONLY_FOR_ARCHS=	i386
USE_LINUX=	yes
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME=	ed2k_gui

do-extract:
	@${RM} -rf ${WRKDIR}
	@${MKDIR} ${WRKDIR}
	@${CP} ${DISTDIR}/${DISTNAME} ${WRKSRC}/${BINARY_NAME}

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

.include <bsd.port.post.mk>
