# New ports collection makefile for:	kwebsearch
# Date created:		11 Dec 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kwebsearch
PORTVERSION=	1.2
CATEGORIES=	www kde
MASTER_SITES=	http://www.guruz.de/

MAINTAINER=	ports@FreeBSD.org

BUILD_DEPENDS=	msgfmt:${PORTSDIR}/devel/gettext

USE_KDELIBS_VER=1
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${X11BASE}" KDEDIR="${LOCALBASE}"
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib

.include <bsd.port.mk>
