# New ports collection makefile for:	Quanta+
# Date created:				26 Sep 2002
# Whom:					AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	quanta
PORTVERSION= 	3.1
PORTREVISION=	1
PORTEPOCH=	2	# dammit! I hate this kludge.
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${KDE_VERSION}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_XPM=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes

CONFIGURE_ARGS+= --with-extra-includes=${LOCALBASE}/include \
		--disable-closure --enable-threads --disable-debug

.include <${.CURDIR}/../../x11/kde3/Makefile.kde>
.include <bsd.port.mk>
