# New ports collection makefile for:   kwatch
# Date created:        23 May 1998
# Whom:                Hans Petter Bieker <zerium@webindex.no>
#
# $FreeBSD$
#

PORTNAME=	kwatch
PORTVERSION=	2.3.0
PORTREVISION=	2
CATEGORIES=	misc kde
MASTER_SITES=	http://www.m-j-s.net/pub/kde/ \
		${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/apps/KDE3.x/admin/

MAINTAINER=	kde@freebsd.org
COMMENT=	KDE/Qt log file viewer

USE_GETTEXT=	yes
USE_GMAKE=	yes
USE_REINPLACE=	yes
USE_KDELIBS_VER=	3
GNU_CONFIGURE=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|-O2 ||g' ${WRKSRC}/configure

.include <bsd.port.mk>
