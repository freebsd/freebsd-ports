# New ports collection makefile for:	kdenlive
# Date created:				15 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.8.2.1
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	SF

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	mlt.4:${PORTSDIR}/multimedia/mlt \
		qjson.0:${PORTSDIR}/devel/qjson

USE_GETTEXT=	yes
USE_KDE4=	kdehier kdelibs kdeprefix automoc4 sharedmime
USE_QT_VER=	4
QT_COMPONENTS=	dbus gui network opengl script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kdenlive.1 kdenlive_render.1

OPTIONS=	DVD	"DVD creation with cdrtools and dvdauthor" on \
		FREI0R	"frei0r plugins" on \
		LADSPA	"LADSPA plugins" on \
		SCREENGRAB	"Screen capture with recordMyDesktop" on \
		XINE	"DVD preview with xine" on

.include <bsd.port.options.mk>

.ifndef(WITHOUT_DVD)
USE_CDRTOOLS=	yes
RUN_DEPENDS+=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor
.endif

.ifndef(WITHOUT_FREI0R)
RUN_DEPENDS+=	frei0r-plugins>=0:${PORTSDIR}/graphics/frei0r-plugins
.endif

.ifndef(WITHOUT_LADSPA)
RUN_DEPENDS+=	swhplugins>=0:${PORTSDIR}/audio/swhplugins
.endif

.ifndef(WITHOUT_SCREENGRAB)
RUN_DEPENDS+=	recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop
.endif

.ifndef(WITHOUT_XINE)
RUN_DEPENDS+=	xine:${PORTSDIR}/multimedia/xine
.endif

post-patch:
	${REINPLACE_CMD} -E -e '/${PORTNAME}.(menu|xpm)/ d' \
		${PATCH_WRKSRC}/data/CMakeLists.txt
	${REINPLACE_CMD} -e '/^update_xdg_mimetypes/ d; /SharedMimeInfo/ d' \
		${PATCH_WRKSRC}/src/mimetypes/CMakeLists.txt

post-install:
	@-update-mime-database ${PREFIX}/share/mime

.include <bsd.port.mk>
