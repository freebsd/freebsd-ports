# New ports collection makefile for:	KMud
# Date created:		31 Oct 1999
# Whom:			Will Andrews <andrews@technologist.com>
#
# $FreeBSD$
#

PORTNAME=	kmud
PORTVERSION=	0.5
CATEGORIES=	net
MASTER_SITES=	${MASTER_SITE_SUNSITE} \
		ftp://ftp.kmud.de/pub/kmud/
MASTER_SITE_SUBDIR=	games/muds

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11
BUILD_DEPENDS=	gettext:${PORTSDIR}/devel/gettext
RUN_DEPENDS=	kdehelp:${PORTSDIR}/x11/kdebase11

BROKEN=		"KDE 1.x is no longer in the ports tree"

USE_QT=		yes
USE_LIBTOOL=	yes
CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include" \
		LIBS="-L${LOCALBASE}/lib" \
		QTDIR="${X11BASE}"
CONFIGURE_ARGS=	--with-qt-includes=${X11BASE}/include/X11/qt \
		--with-qt-libraries=${X11BASE}/lib

pre-patch:
	@${PERL} -pi -e "s|-ldl ||g" ${WRKSRC}/kmud/Makefile.in

.include <bsd.port.mk>
