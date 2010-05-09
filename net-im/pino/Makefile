# New ports collection makefile for:   	pino
# Date created:                         2010-03-14
# Whom:                                 Frank Steinborn <steinex@nognu.de>
#
# $FreeBSD$
#

PORTNAME=	pino
PORTVERSION=	0.2.8
CATEGORIES=	net-im
MASTER_SITES=	GOOGLE_CODE

MAINTAINER=	steinex@nognu.de
COMMENT=	A simple and fast Twitter and Identi.ca client

BUILD_DEPENDS=	${LOCALBASE}/bin/valac:${PORTSDIR}/lang/vala
LIB_DEPENDS=	gee.2:${PORTSDIR}/devel/libgee \
		gtkspell.0:${PORTSDIR}/textproc/gtkspell \
		notify.1:${PORTSDIR}/devel/libnotify \
		soup-2.4.1:${PORTSDIR}/devel/libsoup \
		unique-1.0.2:${PORTSDIR}/x11-toolkits/unique \
		webkit-1.0.13:${PORTSDIR}/www/webkit-gtk2

PROJECTHOST=	pino-twitter
USE_GNOME=	gnomehack intltool libxml2 gtk20 glib20
USE_GETTEXT=	yes
USE_PYTHON_BUILD=	yes
USE_BZIP2=	yes
INSTALLS_ICONS=	yes

post-patch:
	@${REINPLACE_CMD} -e 's|/usr|${PREFIX}|g' \
		${WRKSRC}/indicator/pino

do-configure:
	@cd ${WRKSRC} && ./waf configure --prefix="${PREFIX}"

do-build:
	@cd ${WRKSRC} && ./waf build

do-install:
	@cd ${WRKSRC} && ./waf install

.include <bsd.port.mk>
