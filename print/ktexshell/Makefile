# New ports collection makefile for:	ktexshell
# Date created:				28 March 2001
# Whom:					Dmitry Sivachenko <demon@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	ktexshell
PORTVERSION=	0.4.0
CATEGORIES=	print kde
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	ktexshell

MAINTAINER=	demon@FreeBSD.org

LIB_DEPENDS=	kdecore.4:${PORTSDIR}/x11/kdelibs2 \
		intl.1:${PORTSDIR}/devel/gettext

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
	@${PERL} -pi -e 's#libqt#libqt2#g' ${WRKSRC}/configure
	@${PERL} -pi -e 's#lqt#lqt2#g' ${WRKSRC}/configure ${WRKSRC}/ktexshell/Makefile.in

.include <bsd.port.mk>
