# New ports collection makefile for:	subtitleeditor
# Date created:		08 January 2007
# Whom:			Andrew Pantyukhin <infofarmer@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	subtitleeditor
PORTVERSION=	0.13.2
CATEGORIES=	multimedia
MASTER_SITES=	http://kitone.free.fr/subtitleeditor/files/ CSME

MAINTAINER=	infofarmer@FreeBSD.org
COMMENT=	Subtitle editor

BUILD_DEPENDS=	${LOCALBASE}/libdata/pkgconfig/iso-codes.pc:${PORTSDIR}/misc/iso-codes
RUN_DEPENDS:=	${BUILD_DEPENDS}
LIB_DEPENDS=	gtkmm-2.4.1:${PORTSDIR}/x11-toolkits/gtkmm24 \
		glademm-2.4.1:${PORTSDIR}/devel/libglademm24 \
		enchant.1:${PORTSDIR}/textproc/enchant \
		pcre.0:${PORTSDIR}/devel/pcre-utf8

USE_GNOME=	gtk20
USE_GSTREAMER=	good
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--mandir=${MANPREFIX}/man
CONFIGURE_ENV=	CPPFLAGS="${CPPFLAGS}" LDFLAGS="${LDFLAGS}"
CPPFLAGS=	-I${LOCALBASE}/include
LDFLAGS=	-L${LOCALBASE}/lib
PLIST_SUB=	DESKTOPDIR="${DESKTOPDIR:S,^${PREFIX}/,,}"
MAN1=		${PORTNAME}.1

post-patch:
	@${REINPLACE_CMD} -e '/test/s|==|=|g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e 's|strtoll|std::strtoll|g' ${WRKSRC}/src/SubtitleASS.cc

pre-configure::
	@${ECHO_MSG} ""
	@${ECHO_MSG} "This ports need pcre with utf-8 support. If you already"
	@${ECHO_MSG} "have pcre installed, you may need to run"
	@${ECHO_MSG} "# portupgrade -fo devel/pcre-utf8 pcre"
	@${ECHO_MSG} "for this port to build"
	@${ECHO_MSG} ""
	@sleep 2

.include <bsd.port.mk>
