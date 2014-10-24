# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
# $FreeBSD$
#   $MCom: ports/net/service-discovery-applet/Makefile,v 1.5 2007/08/06 16:57:53 mezz Exp $

PORTNAME=	service-discovery-applet
PORTVERSION=	0.4.3
PORTREVISION=	15
CATEGORIES=	net dns gnome
MASTER_SITES=	http://0pointer.de/~sebest/

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	GNOME applet that shows available network services using mDNS

BUILD_DEPENDS=	${PYTHON_SITELIBDIR}/avahi/__init__.py:${PORTSDIR}/net/py-avahi
RUN_DEPENDS=	${PYTHON_SITELIBDIR}/avahi/__init__.py:${PORTSDIR}/net/py-avahi

USES=		gettext gmake pathfix python
USE_GNOME=	gnomeprefix intlhack pygnomedesktop
GNU_CONFIGURE=	yes
INSTALLS_ICONS=	yes
CONFIGURE_ARGS=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

GCONF_SCHEMAS=	service-discovery-applet.schemas

post-patch:
	@${REINPLACE_CMD} -e 's|%%PREFIX%%|${PREFIX}|g' \
		${WRKSRC}/plugins/gconfterminal.py.in

post-install:
	@${LOCALBASE}/bin/gtk-update-icon-cache -f -q --ignore-theme-index \
		${STAGEDIR}${PREFIX}/share/service-discovery-applet/icons

.include <bsd.port.mk>
