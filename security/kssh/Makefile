# New ports collection makefile for:	kssh
# Date created:		19 Nov 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kssh
PORTVERSION=	0.4.1
CATEGORIES=	security
MASTER_SITES=	http://www.geocities.com/bilibao/

MAINTAINER=	kevlo@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		png.4:${PORTSDIR}/graphics/png \
		kdecore.4:${PORTSDIR}/x11/kdelibs2
BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext

GNU_CONFIGURE=	yes
USE_QT2=	yes
MOC?=           ${X11BASE}/bin/moc2
USE_GMAKE=	yes
CONFIGURE_ARGS+=--prefix="${PREFIX}" --datadir="${LOCALBASE}" \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-includes=${LOCALBASE}/include \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	KDEDIR="${LOCALBASE}" MOC="${MOC}" LIBQT="-lqt2" \
		LIBQTFILE="libqt2"

WRKSRC=		${WRKDIR}/${PORTNAME}-0.4

.include <bsd.port.mk>
