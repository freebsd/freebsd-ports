# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	1.94
CATEGORIES=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	unstable/distribution/2.0Beta5/tar/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib \
		qt2.4:${PORTSDIR}/x11-toolkits/qt22 \
		kdecore.4:${PORTSDIR}/x11/kdelibs2

MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	LIBQT="-lqt2" MOC="${MOC}" LIBQTFILE="libqt2" \
		CPPFLAGS="-I${LOCALBASE}/include -I${X11BASE}/include -D_XOPEN_UNIX" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -L${X11BASE}/lib -lqt2 -ljpeg -lgcc -lstdc++"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s:-lpthread:-pthread:g" ${WRKSRC}/knode/Makefile.in

.include <bsd.port.mk>
