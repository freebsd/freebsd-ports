# New ports collection makefile for:	PolicyKit-kde
# Date created:		2009-02-03
# Whom:			David Naylor <dragonsa@highveldmail.co.za>
#
# $FreeBSD$
#

PORTNAME=	PolicyKit-kde
PORTVERSION=	${EXTRA_VER}
CATEGORIES=	sysutils kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${EXTRA_VER}/src/extragear
DIST_SUBDIR=	KDE/extragear

MAINTAINER=	kde@FreeBSD.org
COMMENT=	PolicyKit manager for KDE

LIB_DEPENDS=	polkit.2:${PORTSDIR}/sysutils/policykit

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_KDE4=	kdelibs kdeprefix automoc4
USE_LDCONFIG=	yes
USE_QT_VER=	4
QT_COMPONENTS=	corelib dbus gui network svg xml  \
		qmake_build moc_build rcc_build uic_build
USE_CMAKE=	yes

EXTRA_VER=	4.2.0

.include <bsd.port.mk>
