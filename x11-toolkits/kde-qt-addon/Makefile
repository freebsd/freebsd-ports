# New ports collection makefile for:	KDE libraries 2
# Date created:				Fri Apr 14 2000 15:05:00 EDT
# Whom:					will
#
# $FreeBSD$
#

PORTNAME=	kde-qt-addon
PORTVERSION=	20000724A
CATEGORIES=	x11-toolkits
MASTER_SITES=	${MASTER_SITE_LOCAL}
MASTER_SITE_SUBDIR=	will

MAINTAINER=	will@FreeBSD.org

LIB_DEPENDS=	qt2.4:${PORTSDIR}/x11-toolkits/qt22

BROKEN=		"Not needed with the current KDE2 snapshots"
WRKSRC=		${WRKDIR}/${PORTNAME}
MOC?=		${X11BASE}/bin/moc2
SOMAJOR=	4
SOMINOR=	0
USE_BZIP2=	yes
USE_NEWGCC=	yes
INSTALLS_SHLIB=	yes
USE_AUTOCONF=	yes
CONFIGURE_ARGS+=--with-qt-dir=${X11BASE} \
		--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV+=	LIBS="-Wl,-export-dynamic -L${X11BASE}/lib -L${LOCALBASE}/lib -lqt2 -ljpeg -lgcc -lstdc++" \
		CPPFLAGS="-I${X11BASE}/include -I${LOCALBASE}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2"
USE_GMAKE=	yes
MAKE_ENV+=	SOMAJOR="${SOMAJOR}" SOMINOR="${SOMINOR}"

pre-configure:
	${PERL} -pi -e "s@version-info 3:0@version-info ${SOMAJOR}:${SOMINOR}@g" ${WRKSRC}/kde-qt-addon/Makefile.in

pre-install:
	@(find ${WRKSRC} -name CVS | xargs rm -rf)

.include <bsd.port.mk>
