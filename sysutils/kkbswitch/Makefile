# New ports collection makefile for:	kkbswitch
# Date created:				01 Oct 2003
# Whom:					Rashid N. Achilov <shelton@granch.ru>
#
# $FreeBSD$
#

PORTNAME=		kkbswitch
PORTVERSION=		1.3.1
PORTREVISION=	1
CATEGORIES=		sysutils kde
MASTER_SITES=		${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	kkbswitch

MAINTAINER=		shelton@granch.ru
COMMENT=		Keyboard layout switcher and indicator for KDE 3.x

USE_KDELIBS_VER=	3
USE_GMAKE=		yes
GNU_CONFIGURE=		yes

CONFIGURE_ARGS += 	--with-qt-dir=${QT_PREFIX} \
			--with-extra-includes=${LOCALBASE}/include \
			--with-extra-libs=${LOCALBASE}/lib

CONFIGURE_TARGET=

PLIST_SUB=		PREFIX=${PREFIX} \
			X11BASE=${X11BASE}

.include <bsd.port.mk>
