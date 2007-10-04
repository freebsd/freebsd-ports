# New ports collection makefile for:   PolicyKit
# Date Created:			01 May 2006
# Whom:				Joe Marcus Clarke <marcus@FreeBSD.org>
#
# $FreeBSD$
#   $MCom: ports/sysutils/policykit/Makefile,v 1.12 2006/10/07 19:45:38 marcus Exp $
#

PORTNAME=	policykit
PORTVERSION=	0.1.20060514
PORTREVISION=	4
CATEGORIES=	sysutils gnome
MASTER_SITES=	http://www.marcuscom.com/downloads/
DISTNAME=	PolicyKit-${PORTVERSION}

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Framework for controlling access to system-wide components

LIB_DEPENDS=	dbus-glib-1.2:${PORTSDIR}/devel/dbus-glib

USE_BZIP2=	yes
USE_GNOME=	gnomehack gnometarget
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
CONFIGURE_ARGS=	--disable-gtk-doc \
		--with-pid-file=/var/run/polkitd/polkitd.pid \
		--with-pam-include=system
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib" \
		GTKDOC="false"

USE_RC_SUBR=	polkitd
USE_GNOME_SUBR=	yes

post-install:
.if !defined(PACKAGE_BUILDING)
	@${SETENV} PKG_PREFIX=${PREFIX} ${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL
.endif

.include <bsd.port.mk>
