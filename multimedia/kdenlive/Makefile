# New ports collection makefile for:	kdenlive
# Date created:				15 October 2008
# Whom:					Alberto Villa <villa.alberto@gmail.com>
#
# $FreeBSD$

PORTNAME=	kdenlive
PORTVERSION=	0.9.2
PORTREVISION=	1
CATEGORIES=	multimedia kde
MASTER_SITES=	${MASTER_SITE_KDE}
MASTER_SITE_SUBDIR=	stable/${PORTNAME}/${PORTVERSION}/src/

MAINTAINER=	avilla@FreeBSD.org
COMMENT=	KDE professional quality non-linear video editing suite

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

LIB_DEPENDS=	mlt.5:${PORTSDIR}/multimedia/mlt \
		qjson.0:${PORTSDIR}/devel/qjson

USE_KDE4=	kdehier kdelibs kdeprefix automoc4 sharedmime
USE_QT4=	dbus gui opengl script svg xml \
		moc_build qmake_build rcc_build uic_build
USE_XORG=	x11
USE_BZIP2=	yes
USE_CMAKE=	yes
MAKE_JOBS_SAFE=	yes

MAN1=		kdenlive.1 kdenlive_render.1

OPTIONS=	DVD	"DVD creation with cdrtools and dvdauthor" on \
		FREI0R	"frei0r video plugins" on \
		LADSPA	"LADSPA audio plugins" on \
		SCREENGRAB	"Screen capture with recordMyDesktop" on \
		XINE	"DVD preview with xine" on

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MDVD}
RUN_DEPENDS+=	dvdauthor:${PORTSDIR}/multimedia/dvdauthor
USE_CDRTOOLS=	yes
.endif

.if ${PORT_OPTIONS:MFREI0R}
RUN_DEPENDS+=	frei0r-plugins>=0:${PORTSDIR}/graphics/frei0r-plugins
.endif

.if ${PORT_OPTIONS:MLADSPA}
RUN_DEPENDS+=	swhplugins>=0:${PORTSDIR}/audio/swhplugins
.endif

.if ${PORT_OPTIONS:MNLS}
USE_GETTEXT=	yes
PLIST_SUB+=	NLS=""
.else
CMAKE_ARGS+=	-DBUILD_po:BOOL=FALSE
PLIST_SUB+=	NLS="@comment "
.endif

.if ${PORT_OPTIONS:MSCREENGRAB}
RUN_DEPENDS+=	recordmydesktop:${PORTSDIR}/multimedia/recordmydesktop
.endif

.if ${PORT_OPTIONS:MXINE}
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
