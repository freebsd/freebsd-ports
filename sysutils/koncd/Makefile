# New ports collection makefile for:	koncd
# Date created:				2 April 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	koncd
PORTVERSION=	0.7.1
CATEGORIES=	sysutils kde
MASTER_SITES=	http://www.koncd.de/download/ \
		ftp://apps.kde.com/pub/Multimedia/Audio/Burners_Rippers/KOnCD/

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2
RUN_DEPENDS=	cdrecord:${PORTSDIR}/sysutils/cdrecord \
		mkisofs:${PORTSDIR}/sysutils/mkisofs

USE_QT2=	yes
MOC?=		${X11BASE}/bin/moc2
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS+=--with-qt-includes=${X11BASE}/include/qt2 \
		--with-qt-libraries=${X11BASE}/lib \
		--with-extra-libs=${LOCALBASE}/lib
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include -I${PREFIX}/include" \
		MOC="${MOC}" LIBQT="-lqt2" LIBQTFILE="libqt2" \
		LIBS="-Wl,-export-dynamic -L${LOCALBASE}/lib -ljpeg -lgcc -lstdc++"

post-patch:
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure

.include <bsd.port.mk>
