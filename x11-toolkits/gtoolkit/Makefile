# New ports collection makefile for:   gtoolkit
# Date created:        13 Jan 2002
# Whom:                Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtoolkit
PORTVERSION=	0.9.5
PORTREVISION=	3
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.inf.uos.de/pub/elmar/gtk/objc-gtoolkit/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Obj-C wrapper for gtk, a x11 graphics library

USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_GNUSTEP=	yes
USE_GNUSTEP_PREFIX=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
GNU_CONFIGURE=	yes
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes

MAKE_ARGS+=	GNUSTEP_PREFIX=${PREFIX}/System
CONFIGURE_ARGS+=	--with-gnustep
WRKSRC=		${WRKDIR}/${DISTNAME}/GToolKit
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	${REINPLACE_CMD} -e 's#gtk-config#${GTK_CONFIG}#g' \
		${CONFIGURE_WRKSRC}/configure
	${REINPLACE_CMD} -e 's|)/Makefiles|)/Library/Makefiles|' \
		${WRKSRC}/Makefile.gnustep

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		gtksignal.h is missing from gtk
.endif

.include <bsd.port.post.mk>
