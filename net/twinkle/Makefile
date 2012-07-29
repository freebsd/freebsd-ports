# New ports collection makefile for:	twinkle
# Date created:		2006-04-22
# Whom:			Jose Alonso Cardenas Marquez <acm@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	twinkle
PORTVERSION=	1.4.2
PORTREVISION=	6
CATEGORIES=	net
MASTER_SITES=	http://www.xs4all.nl/~mfnboer/twinkle/download/

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Soft phone for your VoIP communications using the SIP protocol

BUILD_DEPENDS=	qmake:${PORTSDIR}/devel/qmake
LIB_DEPENDS=	ccgnu2-1.7.0:${PORTSDIR}/devel/commoncpp \
		ccrtp1-1.7.0:${PORTSDIR}/devel/ccrtp \
		sndfile.1:${PORTSDIR}/audio/libsndfile \
		boost_regex.4:${PORTSDIR}/devel/boost-libs \
		speex.1:${PORTSDIR}/audio/speex \
		ilbc.0:${PORTSDIR}/net/ilbc \
		zrtpcpp.0:${PORTSDIR}/devel/libzrtpcpp

GNU_CONFIGURE=	yes
USE_AUTOTOOLS=	libtool
USE_BISON=	build
USE_XORG=	xext
USE_GMAKE=	yes
USE_GNOME=	libxml2
USE_PERL5=	yes
USE_QT_VER=	3

OPTIONS=	KDE	"Compile with kde features"	off

CONFIGURE_ARGS=	--with-qt-dir=${QT_PREFIX} QTDIR=${LOCALBASE} \
CONFIGURE_ENV=	QMAKESPEC="${QMAKESPEC}"
MAKE_ENV=	QTDIR=${QT_PREFIX}
SUB_FILES=	pkg-message

QMAKESPEC?=	${LOCALBASE}/share/qt/mkspecs/freebsd-g++

.include <bsd.port.pre.mk>

.if defined(WITH_KDE)
USE_KDELIBS_VER=3
.include <${PORTSDIR}/Mk/bsd.kde.mk>
.else
CONFIGURE_ARGS+=--without-kde
.endif

post-patch:
	@${REINPLACE_CMD} -e 's|-lresolv||g' -e 's|-lbind||g' ${WRKSRC}/${CONFIGURE_SCRIPT}

post-configure:
	@${REINPLACE_CMD} -e 's|-lresolv||g' ${WRKSRC}/src/gui/${MAKEFILE}

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.post.mk>
