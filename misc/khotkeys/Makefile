# New ports collection makefile for:	khotkeys
# Date created:		06 Nov 2000
# Whom:			rse@engelschall.com
#
# $FreeBSD$
#

PORTNAME=	khotkeys
PORTVERSION=	1.0.4
CATEGORIES=	misc kde
MASTER_SITES=	http://dforce.sh.cvut.cz/~seli/en/khotkeys/

MAINTAINER=	ports@FreeBSD.org

LIB_DEPENDS=	kdecore.3:${PORTSDIR}/x11/kdelibs11 \
		kdeui.3:${PORTSDIR}/x11/kdelibs11 \
		kfm.3:${PORTSDIR}/x11/kdelibs11 \
		kfile.3:${PORTSDIR}/x11/kdelibs11
RUN_DEPENDS=	kcontrol:${PORTSDIR}/x11/kdebase11

NO_LATEST_LINK=	yes
USE_BZIP2=	yes
USE_GMAKE=	yes
USE_NEWGCC=	yes
USE_LIBTOOL=	yes
CONFIGURE_ARGS=	"--with-qt-includes=${QTDIR}/include/X11/qt" \
		"--with-extra-includes=${LOCALBASE}/include" \
		"--with-extra-libs=${LOCALBASE}/lib"
CONFIGURE_ENV=	MOC=${X11BASE}/bin/moc QTDIR=${QTDIR}

.if defined(PREFIX)
QTDIR?=		${PREFIX}
.else
QTDIR?=		${X11BASE}
.endif

.include <bsd.port.mk>
