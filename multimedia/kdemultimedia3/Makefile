# New ports collection makefile for:	KDE2 Multimedia
# Date created:				Saturday 2 September 2000
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdemultimedia
PORTVERSION=	1.94
CATEGORIES=	audio kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/distribution/2.0Beta5/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	jpeg.9:${PORTSDIR}/graphics/jpeg \
		kdecore.4:${PORTSDIR}/x11/kdelibs2 \
		qt2.4:${PORTSDIR}/x11-toolkits/qt22

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib
CONFIGURE_ENV+=	MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lstdc++ -lgcc" \
		USER_LDFLAGS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lstdc++ -lgcc"
USE_GMAKE=	yes

.include <bsd.port.mk>
