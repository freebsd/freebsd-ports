# New ports collection makefile for:	subtitleeditor
# Date created:		08 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subtitleeditor
PORTVERSION=	0.34.0
PORTREVISION=	3
CATEGORIES=	multimedia
MASTER_SITES=	http://download.gna.org/${PORTNAME}/0.34/

MAINTAINER=	pav@FreeBSD.org
COMMENT=	Subtitle editor

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		gstreamermm-0.10.2:${PORTSDIR}/multimedia/gstreamermm \
		enchant.1:${PORTSDIR}/textproc/enchant \
		pcre.0:${PORTSDIR}/devel/pcre

USE_GMAKE=	yes
USE_GNOME=	gtk20
USE_GSTREAMER=	good
USE_GETTEXT=	yes
INSTALLS_ICONS=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
PLIST_SUB=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"
MAN1=		subtitleeditor.1

.include <bsd.port.pre.mk>

.if ${OSVERSION} < 700043
BROKEN=		does not compile
.endif

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|strtoll|strtoq|g' ${WRKSRC}/plugins/subtitleformats/advancedsubstationalpha/advancedsubstationalpha.cc

.include <bsd.port.post.mk>
