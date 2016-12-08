# Created by: Veniamin Gvozdikov <vg@FreeBSD.org>
# $FreeBSD$

PORTNAME=	mobility
PORTVERSION=	1.2.2
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://dev.gentoo.org/~pesa/distfiles/ \
		LOCAL/vg
PKGNAMEPREFIX=	qt4-
DISTNAME=	qt-${PORTNAME}-${PORTVERSION}_p${DATE}

MAINTAINER=	vg@FreeBSD.org
COMMENT=	Qt APIs for mobile devices and desktop platforms

LICENSE=	LGPL21

LIB_DEPENDS=	libblkid.so:misc/e2fsprogs-libblkid

DATE=	20130703
USES=		pkgconfig qmake shebangfix tar:xz
SHEBANG_FILES=	bin/pathhelper bin/syncheaders
USE_QT4=declarative corelib dbus gui linguist_build moc_build
USE_LDCONFIG=	yes
MOBILITY_MODS=

OPTIONS_DEFINE=	BEARER CONNECTIVITY CONTACTS FEEDBACK GALLERY LOCATION \
		MESSAGING MULTIMEDIA ORGANIZER PUBLISHSUBSCRIBE SENSORS \
		SERVICEFRAMEWORK SYSTEMINFO VERSIT
OPTIONS_SUB=	yes

BEARER_DESC=		Bearer module
CONNECTIVITY_DESC=	Connectivity module
CONNECTIVITY_USE=	qt4=rcc_build

CONTACTS_DESC=		Contacts module
FEEDBACK_DESC=		Feedback module
GALLERY_DESC=		Gallery module
LOCATION_DESC=		Location module
LOCATION_USE=		qt4=rcc_build,sql

MESSAGING_DESC=		Messaging module

MULTIMEDIA_DESC=	Multimedia module
MULTIMEDIA_LIB_DEPENDS=	libpulse.so:audio/pulseaudio
MULTIMEDIA_BUILD_DEPENDS=	v4l_compat>=1.0.20120501:multimedia/v4l_compat
MULTIMEDIA_USE=		qt4=opengl gstreamer=bad

ORGANIZER_DESC=		Organizer module
PUBLISHSUBSCRIBE_DESC=	Publishsubscribe module
SENSORS_DESC=		(BROKEN) Sensors module
SERVICEFRAMEWORK_DESC=	(BROKEN) ServiceFramework module
SERVICEFRAMEWORK_USE=	qt4=sql

SYSTEMINFO_DESC=	(BROKEN) Systeminfo module
SYSTEMINFO_USE=		qt4=network
VERSIT_DESC=		Versit module
VERSIT_USE=		qt4=rcc_build

OPTIONS_DEFAULT=BEARER CONNECTIVITY CONTACTS FEEDBACK GALLERY LOCATION \
		MESSAGING MULTIMEDIA ORGANIZER PUBLISHSUBSCRIBE VERSIT

pre-configure:
# Dirty hack because configure find paths and define empty if not found
	@${MKDIR} ${STAGE}${PREFIX}/${QT_BINDIR_REL} \
		${STAGE}${PREFIX}/${QT_INCDIR_REL} \
		${STAGE}${PREFIX}/${QT_LIBDIR_REL} \
		${STAEG}${PREFIX}/${QT_PLUGINDIR_REL}

	cd ${WRKSRC} && ./configure \
		-release \
		-prefix ${STAGE}${PREFIX} \
		-bindir ${STAGE}${PREFIX}/${QT_BINDIR_REL} \
		-headerdir ${STAGE}${PREFIX}/${QT_INCDIR_REL} \
		-libdir ${STAGE}${PREFIX}/${QT_LIBDIR_REL} \
		-plugindir ${STAEG}${PREFIX}/${QT_PLUGINDIR_REL} \
		-modules "${MOBILITY_MODS}"

post-configure:
	${REINPLACE_CMD} -e 's|#include <linux/types.h>||g' \
		${WRKSRC}/plugins/multimedia/gstreamer/qgstreamervideoinputdevicecontrol.cpp \
		${WRKSRC}/plugins/multimedia/gstreamer/camerabin/camerabincontrol.cpp \
		${WRKSRC}/plugins/multimedia/gstreamer/qgstreamerserviceplugin.cpp \
		${WRKSRC}/plugins/multimedia/gstreamer/mediacapture/qgstreamerv4l2input.cpp \
		${WRKSRC}/plugins/multimedia/v4l/radio/v4lradiocontrol.h

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MBEARER}
MOBILITY_MODS+=	bearer
.endif

.if ${PORT_OPTIONS:MCONNECTIVITY}
MOBILITY_MODS+=	connectivity
.endif

.if ${PORT_OPTIONS:MCONTACTS}
MOBILITY_MODS+=	contacts
.endif

.if ${PORT_OPTIONS:MFEEDBACK}
MOBILITY_MODS+=	feedback
.endif

.if ${PORT_OPTIONS:MGALLERY}
MOBILITY_MODS+=	gallery
.endif

.if ${PORT_OPTIONS:MLOCATION}
MOBILITY_MODS+=	location
.endif

.if ${PORT_OPTIONS:MMESSAGING}
MOBILITY_MODS+=	messaging
.endif

.if ${PORT_OPTIONS:MMULTIMEDIA}
MOBILITY_MODS+=	multimedia
.endif

.if ${PORT_OPTIONS:MORGANIZER}
MOBILITY_MODS+=	organizer
.endif

.if ${PORT_OPTIONS:MPUBLISHSUBSCRIBE}
MOBILITY_MODS+=	publishsubscribe
.endif

.if ${PORT_OPTIONS:MSENSORS}
MOBILITY_MODS+=	sensors
BROKEN=		Sensors has not worked yet
.endif

.if ${PORT_OPTIONS:MSERVICEFRAMEWORK}
MOBILITY_MODS+=	serviceframework
BROKEN=		Serviceframework has not worked yet
.endif

.if ${PORT_OPTIONS:MSYSTEMINFO}
MOBILITY_MODS+=	systeminfo
BROKEN=		Systeminfo has not worked yet
.endif

.if ${PORT_OPTIONS:MVERSIT}
MOBILITY_MODS+=	versit
.endif

.if ${PORT_OPTIONS:MCONNECTIVITY} || ${PORT_OPTIONS:MFEEDBACK} || \
	${PORT_OPTIONS:MGALLERY} || ${PORT_OPTIONS:MLOCATION} || \
	${PORT_OPTIONS:MPUBLISHSUBSCRIBE} || ${PORT_OPTIONS:MVERSIT}
PLIST_SUB+=	IDIR=""
.else
PLIST_SUB+=	IDIR="@comment "
.endif

.if ${PORT_OPTIONS:MFEEDBACK} && ${PORT_OPTIONS:MMULTIMEDIA} && \
	${PORT_OPTIONS:MVERSIT}
PLIST_SUB+=	VERSITFEEDBACK=""
.else
PLIST_SUB+=	VERSITFEEDBACK="@comment "
.endif

.if ${PORT_OPTIONS:MORGANIZER} && ${PORT_OPTIONS:MVERSIT}
PLIST_SUB+=	VERSITORGANIZER=""
.else
PLIST_SUB+=	VERSITORGANIZER="@comment "
.endif

.include <bsd.port.mk>
