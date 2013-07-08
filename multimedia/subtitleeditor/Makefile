# Created by: Andrew Pantyukhin <infofarmer@FreeBSD.org>
# $FreeBSD$

PORTNAME=	subtitleeditor
PORTVERSION=	0.40.0
PORTREVISION=	2
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/${PORTNAME}/${PORTVERSION:C/\.[0-9]*$//}/ \
		CRITICAL

MAINTAINER=	ehaupt@FreeBSD.org
COMMENT=	Subtitle editor

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gstreamermm-0.10.2:${PORTSDIR}/multimedia/gstreamermm \
		enchant:${PORTSDIR}/textproc/enchant \
		pcre:${PORTSDIR}/devel/pcre

USES=		gmake
USE_GNOME=	gtk20
USE_GSTREAMER=	good
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_SUB=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"
MAN1=		subtitleeditor.1

OPTIONS_DEFINE=	NLS

.include <bsd.port.options.mk>

.if ${PORT_OPTIONS:MNLS}
USES+=		gettext
PLIST_SUB+=	NLS=""
.else
CONFIGURE_ARGS+=--disable-nls
PLIST_SUB+=	NLS="@comment "
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|strtoll|strtoq|g' ${WRKSRC}/plugins/subtitleformats/advancedsubstationalpha/advancedsubstationalpha.cc
	@${REINPLACE_CMD} -e 's|glib/.*\.h>|glib.h>|g' ${WRKSRC}/plugins/actions/findandreplace/findandreplace.cc

.include <bsd.port.mk>
