PORTNAME=	gnome-user-share
PORTVERSION=	47.2
CATEGORIES=	www deskutils gnome
MASTER_SITES=	GNOME
DIST_SUBDIR=	gnome

MAINTAINER=	gnome@FreeBSD.org
COMMENT=	Personal file-sharing service for the GNOME Desktop

LICENSE=	GPLv2+

RUN_DEPENDS=	${APACHE_PKGNAMEPREFIX}mod_dnssd>=0:www/mod_dnssd \
		console-kit-daemon:sysutils/consolekit2

USES=		apache gettext gnome meson pkgconfig tar:xz
USE_GNOME=	glib20
MESON_ARGS=	-Dmodules_path=${LOCALBASE}/${APACHEMODDIR} \
		-Dsystemduserunitdir=${PREFIX}/lib/systemd/user

GLIB_SCHEMAS=	org.gnome.desktop.file-sharing.gschema.xml

post-patch:
	@${REINPLACE_CMD} -e '/socket/s,PF_INET,AF_INET,' \
		${WRKSRC}/src/http.c
	@${REINPLACE_CMD} -e '/AuthGroupFile/s,/usr,${PREFIX},' \
		${WRKSRC}/data/dav_user_2.4.conf

post-install:
	@${RM} -r ${STAGEDIR}${PREFIX}/lib/systemd

.include <bsd.port.mk>
