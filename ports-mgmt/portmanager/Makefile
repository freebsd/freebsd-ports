# New ports collection makefile for:	portManager
# Date created: 	April 23, 2004
# Whom: 		Michael C. Shultz <ringworm@inbox.lv>
#
# $FreeBSD$
#

PORTNAME=		portmanager
PORTVERSION=		0.1.3
CATEGORIES=		sysutils
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	portmanager

MAINTAINER=		ringworm@inbox.lv
COMMENT=		FreeBSD port management software

BUILD_DEPENDS=		c2html:${PORTSDIR}/textproc/c2html

GNU_CONFIGURE=		yes
CONFIGURE_TARGET=	--build=${ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=		yes
.include <bsd.port.mk>
