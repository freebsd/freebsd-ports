# New ports collection makefile for:   gtoolkit
# Date created:        13 Jan 2002
# Whom:                Miguel Mendez <flynn@energyhq.homeip.net>
#
# $FreeBSD$
#

PORTNAME=	gtoolkit
PORTVERSION=	0.9.5
PORTREVISION=	2
CATEGORIES=	x11-toolkits
MASTER_SITES=	ftp://ftp.inf.uos.de/pub/elmar/gtk/objc-gtoolkit/

MAINTAINER=	dinoex@FreeBSD.org
COMMENT=	Obj-C wrapper for gtk, a x11 graphics library

PREFIX=		${LOCALBASE}/GNUstep
NO_MTREE=	yes
USE_GMAKE=	yes
USE_GNOME=	gtk12
USE_GNUSTEP=	yes
USE_GNUSTEP_BASE=	yes
USE_GNUSTEP_CONFIGURE=	yes
USE_GNUSTEP_BUILD=	yes
USE_GNUSTEP_INSTALL=	yes
GNU_CONFIGURE=	yes
LDCONFIG_DIRS=	${LOCALLIBDIR}
INSTALLS_SHLIB=	yes

MAKE_ARGS+=	GNUSTEP_SYSTEM_ROOT=${PREFIX}/System
CONFIGURE_ARGS+=	--with-gnustep
WRKSRC=		${WRKDIR}/${DISTNAME}/GToolKit
CONFIGURE_WRKSRC=	${WRKDIR}/${DISTNAME}

post-patch:
	@${MV} ${CONFIGURE_WRKSRC}/configure ${CONFIGURE_WRKSRC}/configure.sed
	${SED} -e 's#gtk-config#gtk12-config#g' \
		${CONFIGURE_WRKSRC}/configure.sed \
		> ${CONFIGURE_WRKSRC}/configure
	${CHMOD} +x ${CONFIGURE_WRKSRC}/configure

.include <bsd.port.pre.mk>

.if ${ARCH} == "ia64"
BROKEN=		gtksignal.h is missing from gtk
.endif

.include <bsd.port.post.mk>
