# New ports collection makefile for:	kdenetwork2
# Date created:				Sun May 14 00:55:45
# Whom:					Will Andrews <will@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	kdenetwork
PORTVERSION=	2.1
CATEGORIES=	net news kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTVERSION}/distribution/tar/generic/src

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	uu.1:${PORTSDIR}/converters/uulib \
		kdecore.4:${PORTSDIR}/x11/kdelibs2

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_BZIP2=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	LIBQT="-lqt2" MOC="${MOC}" \
		CPPFLAGS="-I/usr/include -D_PTH_H_ -D_PTH_PTHREAD_H_ -D_GETOPT_H -D_XOPEN_UNIX -I${LOCALBASE}/include" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"
USE_GMAKE=	yes

pre-configure:
	${PERL} -pi -e "s:-lpthread:-pthread:g" ${WRKSRC}/knode/Makefile.in
	${PERL} -pi -e "s@all_includes=\"@all_includes=\"-I/usr/include @g" ${WRKSRC}/acinclude.m4 ${WRKSRC}/aclocal.m4

.include <bsd.port.mk>
