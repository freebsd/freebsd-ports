# New ports collection makefile for:	eDonkey2000 GTK GUI for 'core' client
# Date created:				Fri Jan 4 22:44:56 BRST 2002
# Whom:			Mario Sergio Fujikawa Ferreira <lioux@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	edonkey
PORTVERSION=	0.2.0.a.${SNAPSHOT_DATE:S/-/./g}
PORTREVISION=	1
CATEGORIES=	net linux
MASTER_SITES=	http://users.aber.ac.uk/tpm01/
PKGNAMEPREFIX=	linux-
PKGNAMESUFFIX=	-gui-gtk
DISTNAME=	ed2k_linux_gui_0.2-${SNAPSHOT_DATE}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Linux GTK GUI to eDonkey2000 'core' command line client

RUN_DEPENDS=	donkey:${PORTSDIR}/net/linux-edonkey-core \
		${LINUXBASE}/usr/lib/libgtk-1.2.so.0:${PORTSDIR}/x11-toolkits/linux-gtk

BROKEN=		Unfetchable

ONLY_FOR_ARCHS=	i386
PREFIX?=	${X11BASE}
NO_WRKSUBDIR=	yes
NO_BUILD=	yes
STRIP=

STRIP_CMD=	${LINUXBASE}/usr/bin/strip

.if exists(/usr/bin/brandelf)
BRANDELF?=	/usr/bin/brandelf
.else
BRANDELF?=	brandelf
.endif

BINARY_NAME=	linux_gui_unstable
BINARY_NAME_INSTALL=	linux-edonkey-gui-gtk
PLIST_FILES=	bin/linux-edonkey-gui-gtk
SNAPSHOT_DATE=	2002-02-22

do-install:
	@${INSTALL_PROGRAM} ${WRKSRC}/${BINARY_NAME} ${PREFIX}/bin/${BINARY_NAME_INSTALL}

.include <bsd.port.pre.mk>

pre-install:
.if exists(${STRIP_CMD})
	@${STRIP_CMD} ${WRKSRC}/${BINARY_NAME}
.endif
	@${BRANDELF} -t Linux ${WRKSRC}/${BINARY_NAME}

.include <bsd.port.post.mk>
