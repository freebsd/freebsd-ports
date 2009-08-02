# New ports collection makefile for:	Quanta+
# Date created:				26 Sep 2002
# Whom:					AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdewebdev
PORTVERSION=	${KDE_VERSION}
PORTREVISION=	2
PORTEPOCH=	2
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@FreeBSD.org
COMMENT=	Comprehensive html/website development environment

BUILD_DEPENDS=	cvsservice:${PORTSDIR}/devel/kdesdk3 \
		xgettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	cvsservice:${PORTSDIR}/devel/kdesdk3 \
		tidy:${PORTSDIR}/www/tidy-lib

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_XORG=	xpm
USE_GMAKE=	yes
USE_AUTOTOOLS=  libtool:22

.include <${.CURDIR}/../../x11/kde3/Makefile.kde>
.include <bsd.port.mk>
