# New ports collection makefile for:	Quanta+
# Date created:				26 Sep 2002
# Whom:					AlanE <alane@freebsd.org>
#
# $FreeBSD$
#

PORTNAME=	kdewebdev
PORTVERSION=	${KDE_VERSION}
PORTEPOCH=	2
CATEGORIES=	www kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION:S/.0//}/src
DIST_SUBDIR=	KDE

MAINTAINER=	kde@freebsd.org
COMMENT=	Comprehensive html/website development environment

BUILD_DEPENDS=	xgettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	tidy:${PORTSDIR}/www/tidy

USE_KDELIBS_VER=3
PREFIX=		${KDE_PREFIX}

USE_BZIP2=	yes
USE_XPM=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
_NO_KDE_CLOSURE=yes

pre-configure:
	@${REINPLACE_CMD} -e 's|grep 3.2|grep 3.3|g' ${WRKSRC}/configure

.include <${.CURDIR}/../../x11/kde3/Makefile.kde>
.include <bsd.port.mk>
